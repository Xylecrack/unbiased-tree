import pandas as pd
import numpy as np
from sklearn.preprocessing import MinMaxScaler

df = pd.read_excel("heart.xlsx")

if "Unnamed: 0" in df.columns:
    df.drop(columns=["Unnamed: 0"], inplace=True)

print("--- (a) ---")
print(df.head())
print(df.tail())

print("\n--- (b) ---")
df.columns = df.columns.str.lower()
print(df.columns)

print("\n--- (c) ---")
dup_count = df.duplicated().sum()
print(f"Duplicates: {dup_count}")
df = df.drop_duplicates()

print("\n--- (d) ---")
q1 = df['chol'].quantile(0.25)
q3 = df['chol'].quantile(0.75)
iqr = q3 - q1

lower = q1 - 1.5 * iqr
upper = q3 + 1.5 * iqr

chol_outliers = df[(df['chol'] < lower) | (df['chol'] > upper)]
print(f"Cholesterol outliers detected: {len(chol_outliers)}")
if not chol_outliers.empty:
    print(chol_outliers)

print("\n--- (e) ---")
median_restbp = df['restbp'].median()

q1 = df['restbp'].quantile(0.25)
q3 = df['restbp'].quantile(0.75)
iqr = q3 - q1

lower = q1 - 1.5 * iqr
upper = q3 + 1.5 * iqr

outlier_mask = (df['restbp'] < lower) | (df['restbp'] > upper)
print(f"RestBP outliers: {outlier_mask.sum()}")
df.loc[outlier_mask, 'restbp'] = median_restbp

print("\n--- (f) ---")
categorical_cols = df.select_dtypes(include=['object', 'string']).columns
print(f"Categorical columns encoded: {list(categorical_cols)}")
df = pd.get_dummies(df, columns=categorical_cols, drop_first=True)

print("\n--- (g) ---")
scaler = MinMaxScaler()
numerical_cols = df.select_dtypes(include=['int64', 'float64']).columns
print(f"Scaling columns: {list(numerical_cols)}")
df[numerical_cols] = scaler.fit_transform(df[numerical_cols])
print(df.head())