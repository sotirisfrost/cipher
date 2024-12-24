# Encryption/Decryption System

## Overview
This program is a basic Encryption/Decryption system implemented in C. It provides two main functionalities:
1. Encoding a message using a user-provided keyword.
2. Decoding an encrypted message back into plaintext.

## Features
- **Encryption**: Converts a plaintext message into an encrypted format using a keyword and a custom cipher.
- **Decryption**: Reverses the encryption process to restore the original message using the same keyword.
- **Input Validation**: Ensures the provided keyword is valid (no duplicate characters).
- **Case Sensitivity Handling**: Automatically converts all inputs to uppercase for uniform processing.

## How to Use
1. **Run the Program**:
   Compile the code with a C compiler and execute the binary.
   ```bash
   gcc -o cipher_program Cipher\ Program.c
   ./cipher_program
