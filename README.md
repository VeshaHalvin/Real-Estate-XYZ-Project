# 🏘️ Real Estate XYZ (C Project with Multilist Structure)

**Real Estate XYZ** is a console-based property sales management system written in C. It simulates a company where each sales agent can manage multiple properties. The project uses a **multilist** data structure to represent the relationship between sales agents (parents) and their listed properties (children).

---

## 📌 Features

### 👨‍💼 Sales Management
- Add, edit, and delete sales agents.
- Track total property sales per agent.
- Handle agent resignation with property reassignment.

### 🏡 Property Management
- Add, edit, and delete properties.
- Support for property types: `Rumah (House)` and `Tanah (Land)`.
- Automatically updates sales totals after property changes.

### 🔁 Resignation Handling
- Sales agents can request to resign.
- Admin or Owner can approve and reassign properties before agent deletion.

### 📊 Reporting
- View all sales agents and their listed properties.
- Count of each property type per agent.
- Display properties by type or in sorted views.

---

## 🧱 Data Structures

### 🔗 Multilist Model
Sales Agent (Parent)
↳ Property 1 (Child)
↳ Property 2 (Child)


### `DataParent`
- `NIPSales`: Unique ID
- `namaSales`: Name of salesperson
- `teleponSales`: Phone number
- `totalPenjualan`: Total sales amount

### `DataChild`
- `nomorProperti`: Property ID
- `jenisProperti`: Property type (`Rumah` or `Tanah`)
- `alamatProperti`: Address
- `hargaProperti`: Price

---

## 📁 Project Structure

Project1.dev/
├── header.h // Data structures & declarations
├── parent_child.c // Core logic for multilist operations
├── resign.c // Sales resignation functionality
├── menu.c // Terminal UI and animation
└── main.c // Entry point (not included but expected)


---

  
