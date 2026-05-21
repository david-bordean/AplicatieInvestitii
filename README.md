# Aplicație de investiții în C++

## Descriere

Acest proiect este o aplicație de consolă scrisă în C++ pentru simularea administrării unui portofoliu de investiții. Utilizatorul poate crea un cont de investitor, poate vizualiza instrumentele financiare disponibile pe piață, poate cumpăra și vinde active și poate urmări soldul, profitul și istoricul tranzacțiilor.

Aplicația include mai multe tipuri de instrumente financiare: acțiuni, criptomonede și obligațiuni.

## Scopul proiectului

Scopul proiectului este demonstrarea conceptelor de programare orientată pe obiect în C++, precum moștenirea, polimorfismul, clasele abstracte, template-urile, excepțiile personalizate și utilizarea unor design pattern-uri precum Singleton, Observer și Strategy.

## Funcționalități principale

- creare și conectare la conturi de investitori;
- vizualizarea pieței financiare;
- afișarea separată a acțiunilor, criptomonedelor și obligațiunilor;
- cumpărarea și vânzarea instrumentelor financiare;
- calcularea soldului liber, balanței totale și profitului;
- afișarea istoricului tranzacțiilor;
- actualizarea prețurilor instrumentelor financiare;
- notificarea investitorilor atunci când piața se schimbă.

## Clasele proiectului

### `InstrumentFinanciar`

Este clasa abstractă de bază pentru toate instrumentele financiare din aplicație. Aceasta conține informațiile comune precum numele instrumentului, prețul curent, prețul de cumpărare și cantitatea deținută.

Definește metode virtuale pentru calculul profitului, calculul valorii totale și clonarea obiectelor, permițând folosirea polimorfismului.

### `Actiune`

Reprezintă un instrument financiar de tip acțiune. Clasa calculează profitul pe baza diferenței dintre prețul curent și prețul de cumpărare.

De asemenea, poate încărca lista de acțiuni disponibile din fișierul `actiuni.in`.

### `Crypto`

Reprezintă un instrument financiar de tip criptomonedă. Pe lângă datele comune, această clasă reține și simbolul criptomonedei, de exemplu `BTC` sau `ETH`.

Clasa permite calculul profitului, afișarea informațiilor specifice și încărcarea criptomonedelor din fișierul `crypto.in`.

### `Obligatiune`

Reprezintă un instrument financiar de tip obligațiune. Pe lângă datele comune, clasa conține rata dobânzii și numărul de ani până la scadență.

Profitul este calculat luând în considerare atât diferența de preț, cât și dobânda acumulată.

### `Investitor`

Reprezintă utilizatorul aplicației. Clasa gestionează portofoliul investitorului, soldul liber și istoricul tranzacțiilor.

Permite cumpărarea și vânzarea instrumentelor financiare, adăugarea sau retragerea fondurilor și calcularea valorii totale a portofoliului.

Această clasă implementează interfața `IObserverPiata`, astfel încât portofoliul investitorului se poate actualiza atunci când piața își modifică prețurile.

### `Piata`

Reprezintă piața financiară a aplicației. Aceasta conține listele de acțiuni, criptomonede și obligațiuni disponibile.

Clasa permite căutarea instrumentelor, afișarea catalogului, actualizarea prețurilor și notificarea investitorilor înregistrați.

`Piata` folosește design pattern-ul Singleton, deoarece aplicația are o singură piață financiară principală.

### `IObserverPiata`

Este o interfață folosită pentru implementarea pattern-ului Observer.

Aceasta definește metoda prin care obiectele interesate, precum investitorii, sunt notificate atunci când piața își actualizează prețurile.

### `IStrategiePret`

Este o interfață folosită pentru implementarea pattern-ului Strategy.

Aceasta definește metoda prin care se generează procentul de modificare a prețurilor.

### `StrategieAleatoare`

Este o implementare concretă a interfeței `IStrategiePret`.

Această clasă generează o variație aleatoare a prețurilor, folosită atunci când aplicația simulează trecerea unei zile.

### `Tranzactie<T>`

Este o clasă template care reprezintă o tranzacție efectuată de investitor.

Reține numele instrumentului, tipul tranzacției, cantitatea și prețul. Este folosită pentru salvarea istoricului de cumpărări și vânzări.

### Clasele de excepții

Fișierul `Exceptii.h` conține clase de excepții personalizate pentru situațiile speciale din aplicație.

Acestea sunt folosite pentru validarea valorilor, verificarea fondurilor, verificarea cantităților și tratarea căutărilor de instrumente.

## Concepte OOP folosite

- clase și obiecte;
- moștenire;
- polimorfism;
- clase abstracte;
- metode virtuale;
- template-uri;
- supraincărcarea operatorilor;
- excepții personalizate;
- gestionarea dinamică a memoriei.

## Design patterns folosite

### Singleton

Folosit în clasa `Piata`, pentru a exista o singură instanță a pieței financiare în aplicație.

### Observer

Folosit pentru notificarea investitorilor atunci când prețurile din piață se actualizează.

### Strategy

Folosit pentru separarea algoritmului de modificare a prețurilor de logica principală a pieței.

## Fișiere de intrare

Aplicația folosește fișiere text pentru încărcarea instrumentelor financiare:

```text
actiuni.in
crypto.in
obligatiuni.in





Review


Aplicație de Investiții - Bordean David Ioan
de Bordean David Ioan



Proiectul meu este o aplicație de consola realizata în C++, care simuleaza o platforma simpla de investitii. Ideea principala este ca un utilizator poate sa isi creeze un cont de investitor, sa vada ce instrumente financiare exista pe piata, sa cumpere sau sa vanda active si sa isi urmareasca portofoliul. Aplicatia include mai multe tipuri de instrumente financiare, cum ar fi actiuni, criptomonede si obligatiuni, ceea ce face proiectul mai interesant decat o simpla gestiune de obiecte.
Din punctul meu de vedere, proiectul este bine ales pentru a demonstra concepte importante de programare orientata pe obiect. Nu este doar un program care afișează niște meniuri, ci are o structura clara, cu clase separate, mostenire, polimorfism, interfete, exceptii si chiar design pattern-uri. Acest lucru arata ca proiectul a fost gandit ca o aplicatie mai mare, nu doar ca un exercitiu simplu.

Scopul proiectului
Scopul proiectului este de a crea o aplicație prin care se poate gestiona un portofoliu de investitii. Utilizatorul poate porni cu un anumit sold initial, apoi poate cumpara instrumente disponibile in piață. Dupa cumparare, acestea apar în portofoliu, iar aplicatia calculeaza automat valoarea totala, soldul liber si profitul.
Un alt scop important este simularea modificarii preturilor. În meniul principal exista optiunea de a trece o zi, iar preturile se actualizeaza automat. Acest lucru face ca aplicatia sa para mai realista, deoarece preturile activelor financiare nu raman fixe.

Structura generala a codului
Codul este impartit in mai multe fisiere, fiecare clasa avand fisierul ei .h si, unde este cazul, fisierul .cpp. Aceasta separare ajuta mult la organizare si face codul mai usor de citit. De exemplu, clasele Actiune, Crypto, Obligatiune, Investitor și Piata sunt separate clar, fiecare avand rolul ei.
Un punct foarte bun este faptul ca proiectul folosește o clasa abstracta de baza, InstrumentFinanciar. Aceasta permite ca toate instrumentele financiare sa fie tratate in mod comun, chiar daca fiecare are detalii specifice. Astfel, portofoliul investitorului poate contine mai multe tipuri de instrumente prin pointeri la clasa de baza.

Clasa InstrumentFinanciar
InstrumentFinanciar este una dintre cele mai importante clase din proiect, deoarece este clasa de baza pentru toate tipurile de active. Ea contine campuri comune, cum ar fi numele instrumentului, pretul curent, pretul de cumparare și cantitatea.
Ce face bine aceasta clasa este ca obliga clasele derivate să implementeze metode precum calculeazaProfit, valoare si clone. Prin aceste metode virtuale, proiectul foloseste polimorfismul intr-un mod corect. De asemenea, clasa valideaza preturile si cantitatea, ceea ce ajuta la evitarea unor date gresite în program.
Metoda afiseaza este utila deoarece ofera o afisare comuna pentru toate instrumentele, iar detaliile specifice sunt completate prin afisareExtra. Aceast lucru reduce repetitia de cod.

Clasele Actiune, Crypto si Obligatiune
Clasa Actiune reprezinta actiunile simple. Ea calculeaza profitul prin diferenta dintre pretul curent si pretul de cumparare, înmulțită cu cantitatea. Este o implementare clara si usor de inteles. In plus, clasa are si metoda getCatalog, care citește actiunile din fisierul actiuni.in.
Clasa Crypto este asemănătoare cu Actiune, dar are in plus simbolul criptomonedei. Acest lucru este normal, deoarece criptomonedele sunt de obicei recunoscute prin simboluri precum BTC sau ETH. Și aici profitul este calculat simplut, iar datele pot fi încărcate din crypto.in.
Clasa Obligatiune este putin mai complexa, deoarece include rata dobanzii și anii pana la scadenta. Aici profitul nu este calculat doar prin diferenta de preț, ci include si dobanda. Acest lucru este un plus, deoarece arată ca fiecare tip de instrument poate avea o logica proprie. Din punctul meu de vedere, aceasta clasa arată cel mai bine avantajul mostenirii si al polimorfismului.

Clasa Investitor
Investitor este clasa care gestionează utilizatorul și portofoliul sau. Ea conține numele investitorului, soldul liber, lista de instrumente detinute și istoricul tranzactiilor. Aceasta clasa este foarte importantă deoarece aici se afla logica principala pentru cumparare, vanzare, adaugare de fonduri și retragere de fonduri.
Un lucru foarte bun este ca portofoliul este gestionat prin pointeri la InstrumentFinanciar, iar obiectele sunt copiate prin metoda clone. Asta înseamnă ca se pastreaza tipul real al obiectului, chiar dacă este stocat prin pointer la clasa de baza. De asemenea, clasa are destructor, constructor de copiere si operator de atribuire, ceea ce arăta atenție la gestionarea memoriei.
Metodele cumpara si vinde sunt bine făcute. La cumparare se verifica dacă exista fonduri suficiente, iar dacă instrumentul exista deja în portofoliu, se actualizeaza cantitatea si pretul mediu de cumparare. La vanzare se verifica daca exista cantitate suficientă și, daca ajunge la zero, instrumentul este eliminat automat din portofoliu.

Clasa Piata
Piata reprezinta piata financiara a aplicatiei. Ea încarcă acțiunile, criptomonedele si obligatiunile din fisiere si permite afisarea sau cautarea lor. Eu cred ca este o clasa bine gandita, deoarece separa clar piata de investitor. Investitorul nu trebuie sa stie cum sunt stocate toate instrumentele, ci doar foloseste piata pentru a cumpara sau a actualiza prețurile.
Un aspect foarte bun este folosirea pattern-ului Singleton. În aplicatie are sens sa existe o singura piatra principala, iar Piata::getInstance() rezolva aceasta problema. De asemenea, piața folosește Observer pentru a anunța investitorii cand preturile se modifica și Strategy pentru modul in care se genereaza modificarile de pret. Metoda actualizeazaPreturi este una dintre cele mai importante, deoarece simuleaza trecerea unei zile.

Interfetele si clasele auxiliare
IObserverPiata este o interfata simpla, dar utila. Ea permite ca un investitor sa fie notificat atunci cand piata se modifica. Acest lucru face codul mai flexibil, pentru ca in viitor ar putea exista si alte clase care sa observe piața.
IStrategiePret si StrategieAleatoare sunt folosite pentru pattern-ul Strategy. Momentan exista o strategie aleatoare, care modifica preturile între 90% și 110% din valoarea initiala. Este o idee buna, deoarece în viitor se pot adăuga ușor strategii mai complexe.
Tranzactie<T> este o clasa template folosită pentru istoricul tranzacțiilor. Ea reține numele instrumentului, tipul tranzactiei, cantitatea și prețul. Folosirea unui template este un plus, deoarece arata ca proiectul foloseste și concepte mai avansate din C++.
Clasele din Exceptii.h sunt foarte utile pentru tratarea erorilor. În loc sa se foloseasca doar mesaje simple sau coduri de eroare, proiectul are excepții clare pentru fonduri insuficiente, cantitate insuficienta, instrument negasit si valori invalide.

Ce face bine proiectul
Cel mai mare avantaj al proiectului este organizarea. Codul este impartit logic, iar clasele au responsabilitati clare. De asemenea, folosirea mostenirii si a polimorfismului este potrivita pentru tema aleasa. Instrumentele financiare chiar au nevoie de comportamente comune si comportamente specifice.
Un alt lucru foarte bun este faptul ca proiectul nu se limiteaza la clase simple, ci include si design pattern-uri. Singleton, Observer si Strategy sunt folosite in contexte potrivite, nu doar puse artificial.
Meniul din main.cpp este destul de complet și permite folosirea aplicatiei fara sa fie nevoie de modificari in cod. Utilizatorul poate crea conturi, se poate conecta, poate vedea piata, poate cumpara si vinde. Pentru un proiect de student, functionalitatea este destul de bogata.

Probleme si posibile imbunatatiri
O imbunatatire ar fi salvarea conturilor in fisiere. Momentan investitorii exista doar cat timp ruleaza programul. Ar fi util ca portofoliile și istoricul tranzactiilor sa fie salvate si reincarcate la pornire.
De asemenea, unele validari ar putea fi extinse. De exemplu, numele instrumentelor nu pot avea spatii, deoarece citirea din fisiere se face cu >>.

Functii care nu sunt folosite momentan
Exista cateva functii care nu sunt folosite direct in meniul actual, dar care sunt utile pentru dezvoltari viitoare. De exemplu, getNrActiuniCreate si getNrCryptoCreate ar putea fi folosite pentru o pagina de statistici, unde se afiseaza cate obiecte de un anumit tip au fost create.
Metoda setStrategie din Piata nu este folosita în meniul actual, dar este foarte utila. In viitor, utilizatorul ar putea alege intre mai multe strategii de modificare a preturilor, cum ar fi strategie conservatoare, agresiva sau bazata pe trend.
Metoda dezinregistreaza ar putea fi folosita cand un investitor este sters sau cand se inchide un cont. De asemenea, areInstrument si getCantitateInstrument pot fi folosite pentru afisari mai rapide sau pentru validari inainte de vanzare. setNume și setSoldLiber pot fi folosite intr-un meniu de editare profil sau administrare cont.

Despre README
README-ul este util deoarece explica pe scurt ce face proiectul, ce clase exista și cum se compileaza aplicatia. Este important pentru ca o persoana care vede proiectul prima data poate intelege rapid structura lui și modul de rulare.

Concluzie
In concluzie, proiectul este bine realizat și arată o înțelegere a programării orientate pe obiect în C++. Nu este perfect și mai poate fi îmbunătățit, mai ales la partea de salvare a datelor și folosirea smart pointerilor, dar pentru un prim proiect este clar, functional si bine structurat. Cel mai important este că ideea proiectului este aplicată coerent, iar clasele chiar colaborează între ele într-un mod logic.
