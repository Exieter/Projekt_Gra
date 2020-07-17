# Projekt_Gra


ZOMBIE_SHOOTER_GAME

Gra typu shooter.
Widok z góry, gra 2D, cała plansza w polu widzenia.

Gracz spawnuje się na środku Otoczenia (mapy), może się poruszać płynnie o  odległość x na boki + po skosach (wypadkowa prędkości x i y)  za pomocą strzałek.

Gracz obraca się w kierunku poruszania.

Gracz może strzelać w kierunku poruszania lub w kierunku, w którym jest obrócony.

Plansza jest w kształcie kwadratu z 4 szczelinami, przez które może wchodzić Zombie.

Dookoła niego zza mapy wyłaniają się Zombie z 1 z 4 losowo wylosowanej pozycji, zmierzając w stronę Gracza.

Gracz nie może chodzić po ścianach, oraz wychodzić poza granicę okna gry

Zombie rozróżnieni na kilka klas - SmallZombie = 15HP,  MediumZombie = 30HP, BigZombie = 45HP.

Gracz strzelając od Zombie odejmuje im 15HP za każde trafienie nabojem.

Przy kolizji Zombie - Bullet (nabój) - Zombie traci 15HP, a nabój znika.

Gdy Zombie <=0 HP  - znika.

Ilość pojawiających się Zombie rośnie z czasem.

Przy kolizji Gracz - Zombie, Gracz traci życie w zależności od czasu tej kolizji.

Kiedy występuje kolizja Gracz - Zombie, Zombie nie porusza się w strone gracza, aż do momentu, aż kolizja znowu nie będzie występować.

Gra kończy się po śmierci gracza, w tym przypadku na planszy pozostaje tylko Gracz, który nie może już strzelać.

Aby zacząć grę od nowa, należy uruchomić ją ponownie



Sterowanie:

Strzałki - poruszanie na boki + skosy.

Spacja - strzelanie.

P - pauza, zatrzymanie gry - nacisnąć ponownie aby wznowić.


