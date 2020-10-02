## Wirtualny świat 2D
Prosty, turowy symulator wirtualnego świata, zawierający różne formy życia. Każda forma życia posiada własne statystyki składające się z inicjatywy i siły danego organizmu. Statystyki mogą się zmieniać w trakcie tury. Pojedyncza forma życia zajmuje jedno pole. Po wykonaniu tury formy życia wykonują akcję stosowną dla ich gatunku. Wybrane pole zajmuje organizm o większej sile (w przypadku, gdy organizmy są tak samo silne wygrywa atakujący). Kolejność ruchu jest ustalana według inicjatywy (w przypadku organizmów o tej samej inicjatywie o pierwszeństwie decyduje wiek). 

Symulator jest wykonany w języku C++ (aplikacja konsolowa).

## Instrukcje do uruchomienia
- Zaimportuj projekt do swojego IDE **lub** 
- Skorzystaj z przygotowanego pliku CMakeLists.txt oraz narzędzi CMake oraz Make z poziomu terminala. W folderze, w którym znajduje się plik CMakeLists.txt wpisz kolejno polecenia:
  - *cmake .*
  - *make*
  - *./wirtualny_swiat*
