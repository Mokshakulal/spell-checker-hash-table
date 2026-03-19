# 📝 Spell Checker using Hash Table (Win32 GUI in C)

A simple **Spell Checker application** developed using **C language** and **Windows API (Win32 GUI)**.  
It uses a **hash table with chaining** for efficient word lookup and provides a graphical user interface for interaction.

---

## 🚀 Features

- Graphical User Interface using Win32 API  
- Real-time spell checking  
- Hash table for fast searching  
- Dictionary-based validation  
- Simple and user-friendly design  
- Efficient collision handling using linked lists  

---

## 🧠 Concepts Used

### 🔹 Hash Table
- Words are stored using a hash function  
- Collisions are handled using **linked lists (chaining)**  
- Provides fast average search time  

### 🔹 Hash Function
- Based on ASCII sum of characters  
- Uses modulo operation with table size (100)  

---

## ⚙️ How It Works

- A predefined dictionary is loaded into the hash table  
- User enters a word in the input field  
- On clicking **CHECK**:
  - The word is searched in the hash table  
  - If found → **"Correct Spelling!"**  
  - If not found → **"Incorrect Spelling!"**  
- **CLEAR** button resets input and output  
- **EXIT** button closes the application  

---

## 📖 Dictionary Words (Sample)

- hello  
- world  
- computer  
- science  
- engineering  
- programming  
- algorithm  
- database  
- network  
- software  
- hardware  
- python  
- java  
- project  
- student  

---

## 🖥️ User Interface

- Input Box → Enter word  
- CHECK Button → Validate spelling  
- CLEAR Button → Reset fields  
- EXIT Button → Close application  
- Result Label → Displays result  

---

## ▶️ Execution

This project was successfully executed and tested in a **Windows environment** using **Win32 API**.

### Steps Performed:

- Code compiled using GCC (MinGW)  
- Executed the generated `.exe` file  
- GUI window launched successfully  
- Words were tested against the dictionary  
- Correct output was displayed for valid and invalid inputs  

---

## 🧪 Sample Test Cases

| Input Word   | Output                  |
|-------------|------------------------|
| hello        | Correct Spelling!      |
| computer     | Correct Spelling!      |
| enginering   | Incorrect Spelling!    |
| python       | Correct Spelling!      |
| progrmming   | Incorrect Spelling!    |

---

## 📸 Output Screenshots

![WhatsApp Image 2026-02-27 at 7 12 15 PM (1)](https://github.com/user-attachments/assets/91137fba-c293-46b3-bd39-add7de30872c)

![WhatsApp Image 2026-02-27 at 7 12 15 PM](https://github.com/user-attachments/assets/d179533b-749d-46f5-a59d-736e56037317)


---

## 📌 Advantages

- Fast word lookup using hashing  
- Simple GUI-based interaction  
- Efficient memory usage  
- Easy to extend with larger dictionaries  

---

## ⚠️ Limitations

- Limited dictionary (static words only)  
- Simple hash function (may cause collisions)  
- No suggestions for incorrect words  
- No file-based dictionary support  

---

## 🔮 Future Enhancements

- Add file-based dictionary support  
- Improve hash function  
- Provide word suggestions  
- Add auto-complete feature  
- Enhance GUI design  

---

## 🎯 Learning Outcomes

- Understanding of **Hash Tables and Linked Lists**  
- Working with **Win32 API**  
- Event-driven programming  
- Memory management in C  
- GUI application development  

---

## 👨‍💻 Author

- Name: Moksha
- Course: B.Tech CSE  
- Project: Spell Checker using Hash Table  

---

## 📜 License

This project is created for **educational purposes only**.

---

## ⭐ Support

If you like this project, consider giving it a ⭐ on GitHub!
