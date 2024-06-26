Library Management System
--------Overview---------
This project is a Library Management System implemented in C. It provides functionalities to manage library members (adherents), documents (articles, books, and magazines), and borrowing transactions (emprunts). The system allows the addition, modification, listing, and searching of members and documents, as well as managing borrowing and return transactions.

--------Features----------
Member Management: Add, modify, list, search, and delete library members.
Document Management: Add, modify, list, search, and delete documents such as articles, books, and magazines.
Borrowing Management: Manage borrowing and returning of documents by members, track overdue items.

----------Data Structures-----------
adherant: Represents a library member with attributes such as name, address, and membership type.
date: Represents a date with day, month, and year.
localisation: Represents the location of a document within the library.
articles: Represents article-specific details.
livres: Represents book-specific details.
magazines: Represents magazine-specific details.
documents: Represents a general document with attributes such as title, code, and type-specific details.
retardataire: Represents a member who has overdue borrowed items.
emprunt: Represents a borrowing transaction with attributes such as member ID, document code, and dates of borrowing and returning.

---------Functions----------
headMessage(): Displays the welcome message.
menu(): Displays the main menu and navigates to different management sections.
empruntMenu(): Manages borrowing transactions.
userMenu(): Manages library members.
documentMenu(): Manages library documents.
ajoutUser(): Adds a new library member.
rechercher(): Searches for a document based on code and type.
Usage
Compile the Code: Use a C compiler to compile the source code.
Run the Program: Execute the compiled program.
Navigate through Menus: Use the menu options to manage members, documents, and borrowing transactions.
Future Improvements
Implement the function bodies for the borrowing and document management functions.
Add error handling and input validation.
Implement a more robust user interface.

--------Contributing---------
Contributions are welcome! Please create a pull request with detailed information about the changes.
