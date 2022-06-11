# v0.1.2
* Pataisyta buvusi v0.1 versija
* nuskaito vartotojų įvedamus reikiamus duomenis (struktūros elementai):
    * studento vardą ir pavardę.
    * namų darbų ir egzamino pažymius.
* Duodama galimybė generuoti pažymius automatiškai.
* main.cpp yra uzduoties versija su std::vector.
* main2.cpp versija naudojanti C masyvą.
* Pažymiu vidurkis yra apskaičiuojamas pagal šią formulią(į "vidurkis" įeina egzamino paž.): 
![chrome_t7Gt8KKzNh](https://user-images.githubusercontent.com/93277138/173189557-250d5751-6f45-464c-9f30-1b32eedcc082.png)
* Taip pat naudojantis medianą.
* Gauti / suvesti duomenys yra isvedami į terminalą pagal šia strukturą: 
![2pav](https://user-images.githubusercontent.com/93277138/173189619-6b113bcd-df58-4f31-9cce-d0165da4d53b.png)



# v0.2
* Yra galimybė naudotis visomis v0.1.2 funkcijomis, tačiau C masyvo versija pašalinta.
* Failų skaitymui yra naudojamas mix būdas.
* Funkcijos prototipai ir struktura aprašyti funkcijos.h file.
* Funkcijos aprašytos funkcijos.cpp file.
* Release yra duodami programai reikalingi .txt failai išskyrus nėra 1 milliono.txt duomenų filo.

# v0.3
* Šioje versijoje pridėtas filo patikrinimas naudojant Exception handling.
* Patikrinama ar nuskaitomas failas nėra tuščias.

# v0.4
* Pridėtas studentu filų generavimas.
* Nuskaityti iš filų studentai yra suskirstomi ir išrašomi į du atskirus failus.
  * Studentai su <5 vidurkiu į "nuskriaustukuX.txt" fila.
  * Studentai su >=5 vidurkiu į "galvociaiX.txt" fila.
* Padalinimo vidurkiu naudojama tik vidurkio formule, o ne mediana.
* Yra apskaiciuojami ir parodomi filu kurimo ir duomenu apdorojimo laikai.

# v0.5
* Pridėtas uzduoties veikimo laiko matavimas testavimo paskirtims.
* Pridetas pasirinkimas tik generuoti faila.
* Pridetos 2 papildomos šios uzduoties versijos naudojant std::list ir std::desque.
* Skirtingoms versijoms sukurti aplankalai:
  * Vector aplankale - **std::vector** versija
  * Desque aplankale - **std::desque** versija
  * List aplankale - **std::list** versija

# v1.0.2
* Pataisyta v1.0 versija.
* Kiekvienai versijai pridetos dvi naujos duomenų skaidymo strategijos:
  1. Strategija: Bendro data konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų".
  2. Strategija: Bendro data konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". 
* Visos 3 strategijos yra pasiekiamos po klausimo "Kuri metoda norite pasirinkti (1,2,3)?"
  * 1 - orginalus v0.5 sprendimas, 2 - 1 strategija, 3 - 2 strategija  
* Prideti isvedimai kiekvieno konteinerio dydzio
