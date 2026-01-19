import pandas as pd

df = pd.read_excel('heart.xlsx')

print("a) Shape of Data:")
print(df.shape)

print("b) Missing Values:")
print(df.isnull().sum())

print("c) Data Types:")
print(df.dtypes)

print("d) Zeros in Each Column:")
print((df == 0).sum())

print("e) Mean Age:")
print(df['Age'].mean())

print("f) Train-Test Split:")
selected_df = df[['Age', 'Sex', 'ChestPain', 'RestBP', 'Chol']]

from sklearn.model_selection import train_test_split
train_df, test_df = train_test_split(selected_df, test_size=0.25, random_state=42)

print("Train shape:", train_df.shape)
print("Test shape:", test_df.shape)
