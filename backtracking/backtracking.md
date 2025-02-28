# Backtracking
## Backtracking-ul inseamna sa generezi toate solutiile unei probleme care accepta "partial candidate solution".
***
Ce inseamna "partial candidate solution"? Sa se genereze un sir crescator de lungime n:
Mai exact sa pp. ca n = 4.
Ai un sir de lungime n = 3, despre care stii ca e crescator. 
Aduci inca un termen si verifici daca sirul a ramas cresctor. 
Daca da, ai obtinut o solutie si o afisezi/salvezi (si continui intorcandu-te la sirul initial n = 3 si verifici alti canditati). 
Daca nu, continui verificand alti candidati pana ramai fara.
***

```
Avem o functie de backtracking si o functie de verificare a solutiei.
Functia de backtracking: Generareaza toate posibilitatile (chiar si incorecte). O(n!) factorial
Functia de verificare a solutiei: Verifica daca solutia partiala/finala este valida. O(n^k) polinomial
```

```
Exemplu: Generarea tuturor permutarilor {1, 2, 3, ..., n}

import numpy as np

def verificare(arr, k):
    return len(set(arr[:(k + 1)])) == len(arr[:(k + 1)])

def bkt(arr, k, n):
    if k == n:
        print(arr)
        return None
    for i in range(1, n + 1):
        arr[k] = i
        if verificare(arr, k):
            bkt(arr, k + 1, n)

bkt(np.zeros(3, dtype=int), 0, 3)
```
