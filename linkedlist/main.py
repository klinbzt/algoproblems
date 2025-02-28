import numpy as np

# class myList:
#     info = None # Campul de informatie
#     next = None # Campul care retine urmatoarea celula, un obiect de tip myList
#     final = None # Campul care retine ultimul nod in myList

#     def __init__(self, info): # Constructorul listei.
#         self.info = info

# def inserareSmechera(lista, nod): # O(1)
#     if lista.final == None: # Avem un singur element in lista
#         lista.next = nod
#         lista.final = nod
#     else:
#         lista.final.next = nod
#         lista.final = nod

# def printeazaLista(lista):
#     while lista != None:
#         print(lista.info, end=' ')
#         lista = lista.next

# n = int(input())
# l = None

# while n > 0:
#     n -= 1
#     x = int(input())

#     if l == None:
#         l = myList(x)
#     else:
#         inserareSmechera(l, myList(x))
# printeazaLista(l)
