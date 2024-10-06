# OOP
## Laboratoare OOP - Universitatea Tehnică a Moldovei (UTM)

### Obiectiv: 
În această lucrare de laborator, studenții vor crea un program simplu pentru gestionarea unei biblioteci de cărți, utilizând concepte fundamentale de Programare Orientată pe Obiecte (POO). Studenții vor învăța cum să definească clase, să creeze obiecte și să implementeze moștenirea de bază.

### Sarcina lucrării:
1. Implementați două clase: Carte și Bibliotecă (sau echivalentele acestora în limbajul ales).
2. Clasa Carte ar trebui să aibă atribute precum titlu, autor și ISBN.
3. Clasa Bibliotecă trebuie să dețină o listă de cărți și metode pentru a adăuga o carte, a elimina o carte și a afișa toate cărțile din bibliotecă.

### Implementare
### Raport pentru Primul Laborator

#### Descrierea Programului

Programul creat gestionează o bibliotecă de cărți folosind C++. Are două clase principale: `Carte` și `Biblioteca`. Utilizatorul poate adăuga, șterge și vizualiza cărți printr-un meniu simplu.

#### Componente

1. **Clasa `Carte`**
   - **Atribute:**
     - `titlu`: Titlul cărții.
     - `autor`: Autorul cărții.
     - `ISBN`: Codul ISBN al cărții.
   - **Constructor:** Inițializează atributele cărții.

2. **Clasa `Biblioteca`**
   - **Atribut:**
     - `carti`: Lista cărților din bibliotecă.
   - **Metode:**
     - `adaugaCarte(const Carte& carte)`: Adaugă o carte în bibliotecă.
     - `stergeCarte(int isbn)`: Șterge o carte după ISBN.
     - `afiseazaCarti() const`: Afișează toate cărțile din bibliotecă.

3. **Funcția `meniu()`**
   - Afișează opțiunile pentru utilizator: adăugare, ștergere, afișare cărți sau ieșire din program.

4. **Funcția `main()`**
   - Creează un obiect `Biblioteca` și permite utilizatorului să interacționeze cu biblioteca printr-un meniu repetitiv.

#### Funcționare

- **Adăugare:** Introduce titlul, autorul și ISBN-ul cărții și o adaugă în bibliotecă.
- **Ștergere:** Caută și șterge cartea după ISBN.
- **Afișare:** Listează toate cărțile din bibliotecă.

Programul oferă o gestionare simplă a cărților și este ușor de utilizat pentru administrarea unei biblioteci mici.