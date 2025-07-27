# GAMEBOX_DB 🎮

## Descrizione del Progetto

**GAMEBOX_DB** è un sistema di database relazionale progettato per la gestione completa di una catena di negozi specializzata in videogiochi e merchandising gaming. Il progetto implementa un modello di dati complesso che gestisce tutti gli aspetti del business, dalle vendite online e fisiche alle LAN party organizzate nei negozi.

## 🎯 Obiettivi del Progetto

Il database è stato progettato per supportare:
- **Gestione multi-negozio**: Amministrazione di una catena di negozi con diversi punti vendita
- **E-commerce integrato**: Vendite online e fisiche unificate
- **Sistema di fidelizzazione**: Tessere clienti con diversi livelli di abbonamento
- **Eventi gaming**: Organizzazione di LAN party con postazioni dedicate
- **Inventario completo**: Gestione di videogiochi, console e merchandise

## 🏗️ Architettura del Database

### Entità Principali

#### 🏪 **Gestione Negozi**
- **NEGOZIO**: Informazioni sui punti vendita (orari, date apertura/chiusura)
- **INDIRIZZO**: Localizzazione geografica dei negozi e clienti

#### 🛍️ **Catalogo Prodotti**
- **PRODOTTO**: Entità generica per tutti i prodotti
- **VIDEOGIOCO**: Specifiche dei videogiochi (genere, PEGI, valutazioni, modalità online)
- **CONSOLE**: Dettagli delle console (modello, memoria, colore)
- **MERCHANDISE**: Articoli di merchandising (magliette, gadget, etc.)
- **PRODUTTORE**: Informazioni sui produttori/sviluppatori

#### 👥 **Gestione Clienti**
- **CLIENTE**: Anagrafica e dati dei clienti
- **TESSERA**: Sistema di abbonamenti a livelli (LV1, LV2, LV3)
- **OFFERTA**: Sconti dedicati ai vari livelli di tessera

#### 📦 **Sistema Ordini**
- **ORDINE**: Gestione acquisti online e fisici
- **SPEDIZIONE**: Tracking e gestione delle spedizioni
- **ACQUISTA**: Relazione many-to-many tra clienti, prodotti e ordini

#### 🎮 **Eventi Gaming**
- **LAN_PARTY**: Sale gaming con eventi dedicati
- **POSTAZIONE**: Singole postazioni da gioco
- **ACCEDERE**: Accessi degli abbonati alle LAN party

### Relazioni Chiave
- **PRESSO**: Disponibilità prodotti per negozio
- Vincoli referenziali con CASCADE per mantenere l'integrità dei dati

## 📊 Query Analitiche Implementate

Il progetto include 6 query analitiche principali:

1. **Top Clienti Online**: Classifica dei clienti con più acquisti online
2. **Bilancio Semestrale**: Analisi economica per periodo specifico
3. **Generi Più Venduti**: Statistiche vendite per genere di videogioco
4. **Utilizzo LAN Party**: Frequentazione sale gaming da parte di abbonati LV3
5. **Redditività Eventi**: Analisi incassi LAN party per tipo di omaggio
6. **Performance Negozi Fisici**: Negozi con maggiori vendite in presenza

## 💻 Implementazione Tecnica

### Database SQL
- **Engine**: MySQL/SQLite compatibile
- **File principale**: `GAMEBOX_SQL.sql`
- **Caratteristiche**:
  - Vincoli di integrità referenziale
  - Indici ottimizzati per le query più frequenti
  - Popolazione dati di esempio

### Applicazione C++
- **File**: `QUERY_GAMEBOX.cpp`
- **Framework**: MySQL Connector/C++
- **Funzionalità**:
  - Connessione sicura al database
  - Esecuzione delle query analitiche
  - Gestione errori e risultati

## 📋 Struttura File del Progetto

```
GAMEBOX_DB/
├── GAMEBOX_SQL.sql           # Script principale del database
├── QUERY_GAMEBOX.cpp         # Applicazione C++ per interrogazioni
├── GAMEBOX_ER_F.pdf          # Diagramma ER completo
├── GAMEBOX_ER_RISTR_F.pdf    # Diagramma ER ristrutturato
├── GAMEBOX_RELAZIONE.pdf     # Documentazione tecnica dettagliata
├── ER.png                    # Schema ER in formato immagine
├── RISTR.png                 # Schema ristrutturato in formato immagine
└── README.md                 # Questo file
```

## 🚀 Come Utilizzare il Progetto

### Prerequisiti
- MySQL Server 8.0+ o SQLite
- Compilatore C++ con supporto C++11
- MySQL Connector/C++ (per l'applicazione C++)

### Installazione Database
```sql
-- Eseguire lo script principale
mysql -u username -p < GAMEBOX_SQL.sql
```

### Compilazione Applicazione C++
```bash
# Esempio per Linux/Windows con MySQL Connector
g++ -o gamebox_queries QUERY_GAMEBOX.cpp -lmysqlcppconn
```

### Configurazione Connessione
Modificare le variabili di connessione in `QUERY_GAMEBOX.cpp`:
```cpp
const string server = "tcp://127.0.0.1:3306";
const string username = "your_username";
const string password = "your_password";
```

## 🎯 Casi d'Uso Principali

1. **Gestione Inventario**: Monitoraggio disponibilità prodotti per negozio
2. **Analisi Vendite**: Report dettagliati per categoria e periodo
3. **Fidelizzazione Clienti**: Gestione tessere e offerte personalizzate
4. **Organizzazione Eventi**: Pianificazione e gestione LAN party
5. **Business Intelligence**: Analisi predittive sui trend di vendita

## 📈 Ottimizzazioni Implementate

- **Indice su disponibilità prodotti**: Ottimizza le query di inventario
- **Partitioning per date**: Migliora le performance su query temporali
- **Vincoli CASCADE**: Mantiene automaticamente l'integrità referenziale

## 👨‍💻 Sviluppatori

Progetto sviluppato come sistema di gestione database per il corso di Basi di Dati.

## 📄 Licenza

Progetto a scopo didattico - Tutti i diritti riservati.
