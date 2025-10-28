# 🏦 Bank Project (C++) — Version 1.1

A modern, modular **Bank Client Management System** built in **C++**, using multiple source files for better organization and scalability.
It allows users to manage client accounts: add, update, delete, find, and perform transactions (deposit & withdraw), all stored locally in a text file.

---

## 📋 Features

* 📂 Manage client records (Account Number, PIN, Name, Phone, Balance)
* ➕ Add new clients
* ✏️ Update client information
* ❌ Delete clients
* 🔍 Find a client by account number
* 💰 Deposit & withdraw funds
* 💾 Persistent storage using `Clients.txt`

---

## 🧱 Project Structure

```
📁 BankProject
 ├── main.cpp             # Entry point of the program
 ├── Utils.h / Utils.cpp  # Helper functions (colors, validation, etc.)
 ├── Client.h / Client.cpp # Client data management
 ├── Transactions.h / Transactions.cpp # Deposit, withdraw, and balance logic
 ├── Menu.h / Menu.cpp    # User interface and main menu logic
 ├── Clients.txt          # Local data file storing client info
 └── README.md            # Project documentation
```

---

## ⚙️ How It Works

* Each client is represented by a **`struct sClient`**.
* Data is stored line by line in `Clients.txt`:

  ```
  AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
  ```
* All features interact with this file for reading, writing, and updating records.

Example:

```
A101#//#1234#//#John Smith#//#555-1234#//#1500.50
A102#//#4321#//#Mary Johnson#//#555-9876#//#3200.75
```

---

## ▶️ How to Run (Updated for v1.1)

The project is ready to run — simply clone or copy the repository files.

1. **Clone the repository**:

   ```bash
   git clone https://github.com/abdulrhmanalbrashi/BankProject.git
   cd BankProject
   ```

2. **Ensure the following files are present**:

   * `main.cpp`
   * `Utils.h / Utils.cpp`
   * `Client.h / Client.cpp`
   * `Transactions.h / Transactions.cpp`
   * `Menu.h / Menu.cpp`
   * `Clients.txt`

3. **Compile & Run**:

   ```bash
   g++ -o bank_app main.cpp Utils.cpp Client.cpp Transactions.cpp Menu.cpp
   ./bank_app
   ```

4. **Or using an IDE**:
   Open the folder in Visual Studio, Code::Blocks, or VS Code → build → run.

---

## 🧠 Concepts Used

* File handling in C++
* Structs & Vectors
* Functions & Enums
* String manipulation
* Modular design (header/source separation)
* Console UI (colors, icons, sounds)

---

## 💡 Future Plans (v1.2 and beyond)

* 🔐 Password-protected admin access
* 🗄️ Switch to JSON or SQLite database
* 💻 GUI interface using Qt or wxWidgets
* 📊 Client statistics and sorting

---

## 👨‍💻 Author

**Abdulrahman Al-Barashi**
📧 Email: [--]
🌐 GitHub: [[https://github.com/abdulrhmanalbrashi](https://github.com/abdulrhmanalbrashi)]

---

## 📄 License

This project is licensed under the **MIT License** — free to use, modify, and distribute.

---------------------------------------------------Translation---------------------------------------------------

# 🏦 نظام البنك (C++) — الإصدار 1.1

مشروع متكامل لإدارة حسابات العملاء مكتوب بلغة **++C**،
يعتمد على تقسيم الكود إلى عدة ملفات لسهولة التطوير والصيانة.
يسمح النظام بإضافة العملاء وتحديث بياناتهم وحذفهم وتنفيذ عمليات الإيداع والسحب.

---

## 📋 مميزات النظام

* 📂 إدارة بيانات العملاء (رقم الحساب – الرقم السري – الاسم – الهاتف – الرصيد)
* ➕ إضافة عملاء جدد
* ✏️ تعديل بيانات العملاء
* ❌ حذف عميل
* 🔍 البحث عن عميل برقم الحساب
* 💰 تنفيذ عمليات الإيداع والسحب
* 💾 حفظ البيانات في ملف نصي محلي (`Clients.txt`)

---

## 🧱 هيكل المشروع

```
📁 BankProject
 ├── main.cpp             # نقطة التشغيل الأساسية
 ├── Utils.h / Utils.cpp  # دوال مساعدة (ألوان، تحقق من الإدخال، إلخ)
 ├── Client.h / Client.cpp # إدارة بيانات العملاء
 ├── Transactions.h / Transactions.cpp # منطق الإيداع والسحب
 ├── Menu.h / Menu.cpp    # واجهة المستخدم والقائمة الرئيسية
 ├── Clients.txt          # ملف البيانات المحلي
 └── README.md            # توثيق المشروع
```

---

## ▶️ طريقة التشغيل (للإصدار 1.1)

1. **استنسخ المشروع (Clone):**

   ```bash
   git clone https://github.com/abdulrhmanalbrashi/BankProject.git
   cd BankProject
   ```

2. **تأكد من وجود الملفات التالية:**

   * `main.cpp`
   * `Utils.h / Utils.cpp`
   * `Client.h / Client.cpp`
   * `Transactions.h / Transactions.cpp`
   * `Menu.h / Menu.cpp`
   * `Clients.txt`

3. **التجميع والتشغيل:**

   ```bash
   g++ -o bank_app main.cpp Utils.cpp Client.cpp Transactions.cpp Menu.cpp
   ./bank_app
   ```

4. **أو من خلال بيئة تطوير (IDE):**
   افتح المجلد في Visual Studio أو Code::Blocks أو VS Code، ثم قم بالبناء (Build) والتشغيل (Run).

---

## 🧠 المفاهيم المستخدمة

* التعامل مع الملفات في C++
* البُنى (Structs) والمتجهات (Vectors)
* الدوال والتعدادات (Enums)
* تنسيق المخرجات
* تصميم برمجي منظم (Modular Design)
* واجهة كونسول تفاعلية (ألوان + رموز + أصوات)

---

## 💡 التطوير المستقبلي (v1.2 وما بعده)

* 🔐 نظام تسجيل دخول للمدير
* 🗄️ دعم قواعد البيانات أو JSON
* 💻 واجهة رسومية (GUI)
* 📊 إحصاءات العملاء والفرز

---

## 👨‍💻 المطور

**عبد الرحمن البراشي**
📧 البريد الإلكتروني: [--]
🌐 GitHub: [[https://github.com/abdulrhmanalbrashi](https://github.com/abdulrhmanalbrashi)]

---

## 📄 الترخيص

هذا المشروع مرخص تحت **رخصة MIT** — يمكنك استخدامه وتعديله وتوزيعه بحرية.
