# Smenul lui Mars - cute tactic
# Smen = Truc

# Se da un vector n si m intervale
# [0, 1, 2, 4, 1]
# pentru fiecare interval, adauga la fiecare element 1

# 1. Solutia naiva:
# Parcurgi fiecare interval si adaugi val
# O (m * n)

# 2. Smenul romanului nostru:
# S-a gandit la sume partiale:

# [i, j] -> Vector separat S[i] += val, S[j + 1] -= val
# for (int i = 1; i <= n; i++) {
#   S[i] += S[i -1] + V[i]
# }
#
# O(n)