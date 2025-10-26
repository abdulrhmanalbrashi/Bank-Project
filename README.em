                                    # 🏦 Bank Project (C++)

A simple console-based **Bank Client Management System** built in **C++**.
It allows users to manage client records (add, update, delete, find, list) stored in a text file (`Clients.txt`).

---

## 📋 Features

* 📂 Store client data (Account Number, PIN Code, Name, Phone, Balance)
* ➕ Add new clients
* ✏️ Update existing client information
* ❌ Delete clients
* 🔍 Find a client by account number
* 📃 List all clients in a formatted table
* 💾 Data persistence using a local text file (`Clients.txt`)

---

## 🧱 Project Structure

```
📁 ProjectFolder
 ├── Solution.h          # Main implementation file (logic and UI)
 ├── Clients.txt         # Data file containing all client records
 └── main.cpp            # Entry point (includes Solution.h)
```

---

## ⚙️ How It Works

* The program uses **struct `sClient`** to represent client data.
* All operations (add, delete, update, etc.) manipulate the `Clients.txt` file.
* Each line in the file is formatted as:

  ```
  AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
  ```

Example:

```
A101#//#1234#//#John Smith#//#555-1234#//#1500.50
A102#//#4321#//#Mary Johnson#//#555-9876#//#3200.75
```

---

## ▶️ How to Run (updated)

This project is provided **ready-to-run**. You will receive all necessary files; place them together in the project folder and run the program.

1. **Clone the repository** (or copy the provided files) to your machine:

   ```
   git clone <repo-url>
   cd <repo-folder>
   ```

2. **Ensure these files are present** in the project root (you will provide them):

   * `Solution.h`
   * `main.cpp`
   * `Clients.txt`

3. **Compile and run**. Example using `g++` from the terminal:

   ```
   g++ -o client_app main.cpp
   ./client_app
   ```

   *If `main.cpp` includes `Solution.h` and the files are in the same folder, the above command will compile and run the console application.*

4. **Using an IDE (optional)**: If you prefer Visual Studio, Code::Blocks or VS Code, simply open the project folder (or create a new Console Application project) and add the provided files. Then build and run from the IDE.

---

## 🧩 Example Interface

```
===========================================
        Main Menue Screen
===========================================
    [1] Show Client List.
    [2] Add New Client.
    [3] Delete Client.
    [4] Update Client Info.
    [5] Find Client.
    [6] Exit.
===========================================
Choose what do you want to do? [1 to 6]?
```

---

## 🧠 Concepts Used

* File Handling in C++
* Structs and Vectors
* Functions and Enums
* String Manipulation
* Console Input/Output Formatting (`iomanip`)

---

## 💡 Future Improvements

* Password-protected admin access
* JSON or database storage instead of text files
* GUI using Qt or wxWidgets
* Sorting and searching features

---

## 👨‍💻 Author

**Abdulrahman Al-Barashi**
📧 Contact: [--]
🌐 GitHub: [https://github.com/abdulrhmanalbrashi]

---

## 📄 License

This project is licensed under the **MIT License** – free to use, modify, and distribute.

------------------------------------------------Translation---------------------------------------------------
                                                             # 🏦 نظام  البنك (C++)

مشروع بسيط يعتمد على **واجهة سطر الأوامر (Console)** مكتوب بلغة **++C**،
يهدف إلى إدارة بيانات العملاء مثل إضافة عميل جديد، تحديث البيانات، حذف عميل، والبحث عن عميل من خلال رقم الحساب.

---

## 📋 مميزات النظام

* 📂 حفظ بيانات العملاء (رقم الحساب، الرقم السري، الاسم، الهاتف، الرصيد)
* ➕ إضافة عملاء جدد
* ✏️ تعديل بيانات العملاء الحاليين
* ❌ حذف عميل من النظام
* 🔍 البحث عن عميل باستخدام رقم الحساب
* 📃 عرض جميع العملاء في جدول منسق
* 💾 تخزين البيانات في ملف نصي (`Clients.txt`)

---

## 🧱 هيكل المشروع

```
📁 مجلد المشروع
 ├── Solution.h          # يحتوي على الكود الأساسي والمنطق البرمجي
 ├── Clients.txt         # ملف البيانات الذي تُخزن فيه معلومات العملاء
 └── main.cpp            # نقطة الدخول إلى البرنامج (يستدعي Solution.h)
```

---

## ⚙️ طريقة عمل النظام

* يستخدم النظام بنية **struct sClient** لتمثيل بيانات العميل.
* جميع العمليات (إضافة، حذف، تعديل، عرض...) تتم عبر التعامل مع ملف `Clients.txt`.
* كل سطر في الملف يمثل سجل عميل واحد ويُخزّن بهذا الشكل:

  ```
  AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
  ```

مثال:

```
A101#//#1234#//#محمد علي#//#777777#//#1500.50
A102#//#5678#//#أحمد سعيد#//#777778#//#3200.75
```

---

## ▶️ طريقة التشغيل (معدلة)

المشروع **جاهز للتشغيل** — سأرسل لك جميع الملفات الضرورية. ضع جميع الملفات معًا في نفس مجلد المشروع ثم قم بتشغيلها كما يلي:

1. **انسخ الملفات أو استخرج الريبو** إلى جهازك:

   ```
   git clone <repo-url>
   cd <repo-folder>
   ```

   أو ببساطة انسخ الملفات التي سأرسلها إلى مجلد جديد.

2. **تأكد من وجود الملفات التالية** في مجلد المشروع (سوف تزودني بها):

   * `Solution.h`
   * `main.cpp`
   * `Clients.txt`

3. **قم بالتجميع والتشغيل**. مثال باستخدام `g++` من الطرفية:

   ```
   g++ -o client_app main.cpp
   ./client_app
   ```

   *إذا كان `main.cpp` يستدعي `Solution.h` وكانت الملفات في نفس المجلد، فسيتم تجميع وتشغيل البرنامج بنجاح.*

4. **باستخدام بيئة تطوير (اختياري)**: يمكنك فتح المجلد في Visual Studio أو Code::Blocks أو VS Code، ثم إنشاء مشروع Console جديد أو إضافة الملفات إلى مشروع موجود، ثم البناء (Build) والتشغيل (Run).

---

## 🧠 المفاهيم المستخدمة

* التعامل مع الملفات في C++
* استخدام **struct** و **vector**
* بناء الدوال (Functions)
* استخدام **Enums**
* تنسيق المخرجات باستخدام المكتبة `iomanip`

---

## 💡 أفكار للتطوير المستقبلي

* نظام دخول آمن (كلمة مرور للمدير)
* تخزين البيانات باستخدام قاعدة بيانات أو بصيغة JSON بدلًا من ملف نصي
* واجهة رسومية (GUI) باستخدام **Qt** أو **wxWidgets**
* إضافة خاصية الفرز والبحث المتقدم

---

## 👨‍💻 المطور

**عبد الرحمن البراشي**
📧 البريد الإلكتروني: [--]
🌐 GitHub: [https://github.com/abdulrhmanalbrashi]

---

## 📄 الترخيص

هذا المشروع مرخص تحت رخصة **MIT License** – يحق لك استخدامه وتعديله وتوزيعه بحرية.
