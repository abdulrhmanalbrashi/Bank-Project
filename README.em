# 🏦 Bank Project (C++) — Version 1.2

A modular, interactive **Bank Management System** built in **C++**, implemented using header-only modules and a single `main.cpp`.
This repository uses `.h` files that contain both declarations and definitions (implementation in headers), so compiling `main.cpp` is sufficient.

---

## 🚀 What's New in v1.2

* ✅ User Management System (Admin & Permissions)
* 🔐 Password Encryption (simple Caesar-style)
* 🎨 Colored console messages & icons
* 📦 Modular headers (`*.h`) for easier organization
* ⚙️ Input validation and better error handling

---

## 📋 Features

**Users**

* Add / update / delete users
* Encrypted password storage
* Permission-based access control
* Prevent deleting Admin or current logged-in user

**Clients**

* Add / update / delete clients
* Search by account number
* Deposit & withdraw operations
* View total balances
* Data persisted in `Clients.txt`

---

## 🧱 Project Structure (headers-only)

```
📁 BankProject
 ├── main.cpp               # Entry point (compile this file)
 ├── Utils.h                # Helper functions (messages, colors, input)
 ├── Client.h               # Client management (read/write/search)
 ├── Transactions.h         # Deposit, withdraw, balance functions
 ├── Users.h                # User management, auth, permissions
 ├── Menu.h                 # Menus and navigation
 ├── Clients.txt            # Client data (sample or empty)
 ├── Users.txt              # User data (sample or empty)
 ├── README.md              # This file
 └── .gitignore             # Recommended (see below)
```

> **Note:** In this project the `.h` files contain function implementations (header-only style). There are no `.cpp` implementation files except `main.cpp`. This keeps compilation simple: compile `main.cpp` only.

---

## ▶️ How to Run

1. **Clone / copy the repository**

```bash
git clone https://github.com/abdulrhmanalbrashi/BankProject.git
cd BankProject
```

2. **Ensure these files are present**

* `main.cpp`
* `Utils.h` `Client.h` `Transactions.h` `Users.h` `Menu.h`
* `Clients.txt` (create if missing)
* `Users.txt` (create if missing)

3. **Compile & run (G++ example)**

```bash
g++ -o bank_app main.cpp
./bank_app
```

Because implementations live in the included headers, compiling `main.cpp` links everything.

4. **Or using an IDE**

* Open the project folder in Visual Studio / Code::Blocks / VS Code and build `main.cpp`.

---

## 🧾 Files to include in the repository (what to push)

**Include**

* `main.cpp`
* `Utils.h`
* `Client.h`
* `Transactions.h`
* `Users.h`
* `Menu.h`
* `Clients.txt` (sample or empty)
* `Users.txt` (sample or empty)
* `README.md`
* `LICENSE` (recommended)

**Do NOT include**

* Compiled binaries (`*.exe`, `*.o`, `*.obj`)
* IDE / environment folders (`.vscode/`, `.vs/`, `.idea/`)

Suggested `.gitignore` (copy to repository root):

```
# Build artifacts
*.exe
*.o
*.obj
*.out

# IDE files
.vscode/
.vs/
.idea/

# OS files
.DS_Store
Thumbs.db
```

---

## 🧠 Concepts Used

* Header-only modular organization
* Structs & enums for data models
* File I/O for persistence (`Clients.txt`, `Users.txt`)
* Simple encryption (Caesar-style) for passwords
* Console colors & Beep sounds (Windows API)
* Input validation utilities

---

## 💡 Recommendations / Next Improvements

* Move implementations from headers into `.cpp` files for clearer compilation and faster builds (scale better for large projects).
* Replace simple encryption with secure hashing (e.g., SHA-256) for real security.
* Add unit tests for core logic (Load/Save, Deposit/Withdraw, Permissions).
* Provide a `setup` script to create `Clients.txt` and `Users.txt` with sample entries.
* Optionally add a `VERSION.md` or “Version History” section to track releases.

---

## 👨‍💻 Author

**Abdulrahman Al-Barashi**
GitHub: [https://github.com/abdulrhmanalbrashi](https://github.com/abdulrhmanalbrashi)

---

## 📄 License

MIT License — see `LICENSE` file for details.

---

# 🏦 نظام إدارة البنك (C++) — الإصدار 1.2 (باختصار: Header-only)

المشروع مُنظّم باستخدام ملفات رأس (`*.h`) تحتوي على التعريفات والتنفيذ، ويوجد ملف `main.cpp` فقط كمصدر يتم تجميعه.

---

## 🚀 الجديد في الإصدار 1.2

* نظام إدارة المستخدمين والصلاحيات
* تشفير كلمات المرور (أسلوب بسيط)
* رسائل ملونة ورموز تفاعلية في الكونسول
* تنظيم الكود في ملفات رأس لتبسيط البناء
* تحسين التحقق من المدخلات ومعالجة الأخطاء

---

## 🧱 هيكل المشروع (Header-only)

```
📁 BankProject
 ├── main.cpp
 ├── Utils.h
 ├── Client.h
 ├── Transactions.h
 ├── Users.h
 ├── Menu.h
 ├── Clients.txt
 ├── Users.txt
 ├── README.md
 └── .gitignore
```

> ملاحظة: إن لم يكن لديك ملفات `.cpp` منفصلة، فكلّ شيء مُضمّن في ملفات الهيدر. يكفي تجميع `main.cpp`.

---

## ▶️ طريقة التشغيل

1. **انسخ أو استنسخ المشروع**

```bash
git clone https://github.com/abdulrhmanalbrashi/BankProject.git
cd BankProject
```

2. **تأكد من وجود الملفات التالية**

* `main.cpp`
* `Utils.h` `Client.h` `Transactions.h` `Users.h` `Menu.h`
* `Clients.txt` و `Users.txt` (إن لم تكن موجودة أنشئهما)

3. **تجميع وتشغيل**

```bash
g++ -o bank_app main.cpp
./bank_app
```

4. **أو افتح المجلد في IDE** (Visual Studio / VS Code / Code::Blocks) وقم بالبناء وتشغيل `main.cpp`.

---

## 📄 التراخيص والمؤلف

المطور: **عبد الرحمن البراشي**
الرابط: [https://github.com/abdulrhmanalbrashi](https://github.com/abdulrhmanalbrashi)

ترخيص: MIT


ملاحظة : Username: Admin
               password :turki


---

## 🕓 Version History

| Version              | Date                    | Description                                                                                                                |
| -------------------- | ----------------------- | -------------------------------------------------------------------------------------------------------------------------- |
| **v1.0**             | Initial Release         | Basic Bank System with client operations (Add, Update, Delete, Search, List). All data stored in `Clients.txt`.            |
| **v1.1**             | Structural Update       | Improved modularity — separated features into header files, added colored messages, and simplified project setup.          |
| **v1.2**             | Security & Users Update | Added user authentication and permissions system, password encryption, and better error handling. Also refined console UI. |
| **v1.3** *(Planned)* | Future Features         | Stronger password hashing (SHA256), SQLite database support, GUI using Qt, and transaction history per client.             |

---

# 🕓 سجل الإصدارات (Version History)

| الإصدار              | التاريخ                  | التغييرات                                                                                              |
| -------------------- | ------------------------ | ------------------------------------------------------------------------------------------------------ |
| **v1.0**             | الإصدار الأول            | نظام بنكي أساسي لإدارة العملاء (إضافة – تعديل – حذف – بحث – عرض). تخزين البيانات في ملف `Clients.txt`. |
| **v1.1**             | تحديث هيكلي              | إعادة تنظيم الكود إلى ملفات رأس منفصلة، تحسين الرسائل الملونة، وتبسيط إعداد المشروع.                   |
| **v1.2**             | تحديث الأمان والمستخدمين | إضافة نظام تسجيل الدخول والصلاحيات، وتشفير كلمات المرور، وتحسين واجهة الكونسول.                        |
| **v1.3** *(مخطط له)* | تطويرات مستقبلية         | تشفير أقوى (SHA256)، دعم قواعد بيانات SQLite، واجهة رسومية GUI، وسجل معاملات لكل عميل.                 |

---
