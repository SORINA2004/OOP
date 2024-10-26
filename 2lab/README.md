# OOP lab2

# Sistem de Management al Studentilor

Acest proiect este un sistem simplu de management al studentilor, care permite inscrierea, afisarea si absolvirea studentilor. De asemenea, permite gestionarea facultatilor si logarea utilizatorului.

## Cerințe

Asigurați-vă că aveți un compilator C++ instalat pentru a putea rula codul. De asemenea, este necesar să creați un folder care să conțină toate fișierele `.txt` necesare pentru funcționarea sistemului.

## Fișiere necesare

Creează un folder numit `data` (sau orice alt nume dorit) în același director cu executabilul și adaugă următoarele fișiere text:

1. `catalog.txt` - pentru a stoca informațiile despre studenți.
2. `graduated.txt` - pentru a stoca informațiile despre studenții absolvenți.
3. `faculties.txt` - pentru a stoca lista facultăților.
4. `log.txt` - pentru a stoca informațiile de autentificare.

## Autentificare

Pentru a accesa sistemul, utilizați următoarele credențiale:

- **Login:** sorina2004
- **Parola:** 2004

Dacă este prima dată când rulați programul, va fi necesar să creați un cont nou. Programul va salva aceste date în fișierul `log.txt`.

## Instrucțiuni de utilizare

1. **Compilare și rulare**: Compilați codul C++ utilizând un compilator de preferință (de exemplu, `g++`):
   ```bash
   g++ main.cpp -o student_management
