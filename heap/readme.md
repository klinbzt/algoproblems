# Heap (Structura de date)

## Folosita pentru a obtine minime si maxime

```plaintext
[1, 2, 3, 4, 0, -1, 100, 12, 423, 11]
```
Vrem sa obtinem elem. maxim?

1. Parcurgem liniar si aflam maximul. **O(n)**
2. Sortam si printam ultimul element. **O(n log n)**
3. **Heappp :D** **O(log n)**

---

## Structura de date -> Arbore binar

### A. Inserare (Push) -> **O(log n)**

Heap-ul trebuie sa pastreze intotdeauna o regula:

(vorbim de valorile din noduri)

Copilul din stanga, copilul din dreapta < tatal (I) -> **relatia de heap**

Inserarea se face in primul nod liber pe care il gasim pe cel mai jos nivel curent al heapului.

```plaintext
[1, 2, 3]
```

1. **Inseram unu in heap:**

```plaintext
nivel 0            1
```

2. **Inseram doi in heap**

```plaintext
nivel 0         1
nivel 1        2
```

Dupa ce am inserat, verificam din nodul nou, daca se respecta (I). Daca nu se respecta, interschimbam valorile tatalui cu copilul. Si continuam verificarea in nodul parinte.

```plaintext
nivel 0            2
nivel 1        1
```

3. **Inseram trei in heap**

```plaintext
nivel 0         1
nivel 1        2        3
```

Acelasi lucru ca mai sus.

```plaintext
nivel 0         3
nivel 1        2        1
```

---

### B. Scoatere (pop) -> **O(log n)**

Vrem sa scoatem 3 din heap si sa-l returnam.

```plaintext
nivel 0         3
nivel 1        2        1    
```

Interschimbam ultima si prima valoare din heap.

```plaintext
nivel 0            1
nivel 1        2        3
```

Si stergem ultima valoare, apoi. Apoi plecand de sus, refacem structura de heap (I).

```plaintext
nivel 0            1
nivel 1        2        
```

```plaintext
nivel 0            2
nivel 1        1
