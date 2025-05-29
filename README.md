# Push Swap

Un projet de l'école 42 qui consiste à trier une pile de nombres entiers en utilisant un ensemble limité d'opérations et en minimisant le nombre d'instructions.

## 📋 Description

**Push Swap** est un algorithme de tri qui utilise deux piles (A et B) et un ensemble d'opérations spécifiques pour trier une liste de nombres entiers. L'objectif est de trier la pile A en ordre croissant avec le minimum d'opérations possible.

## 🎯 Objectifs

- Trier une pile de nombres entiers en utilisant uniquement les opérations autorisées
- Minimiser le nombre d'instructions pour optimiser l'algorithme
- Gérer les erreurs (doublons, débordements, arguments invalides)

## 🔧 Opérations autorisées

### Swap
- `sa` : swap les 2 premiers éléments de la pile A
- `sb` : swap les 2 premiers éléments de la pile B  
- `ss` : `sa` et `sb` en même temps

### Push
- `pa` : prend le premier élément de B et le met au début de A
- `pb` : prend le premier élément de A et le met au début de B

### Rotate
- `ra` : décale tous les éléments de A vers le haut (le premier devient le dernier)
- `rb` : décale tous les éléments de B vers le haut
- `rr` : `ra` et `rb` en même temps

### Reverse rotate
- `rra` : décale tous les éléments de A vers le bas (le dernier devient le premier)
- `rrb` : décale tous les éléments de B vers le bas
- `rrr` : `rra` et `rrb` en même temps

## 🏗️ Structure du projet

```
push_swap/
├── Makefile
├── include/
│   └── push_swap.h
├── libft/                      # Bibliothèque personnelle
├── src/
│   ├── main.c                  # Point d'entrée du programme
│   ├── operations/             # Implémentation des opérations
│   │   ├── push.c
│   │   ├── swap.c
│   │   ├── rotate.c
│   │   └── reverse_rotate.c
│   ├── sort/                   # Algorithmes de tri
│   │   ├── sort.c
│   │   ├── advanced_sort.c
│   │   ├── sort_utils.c
│   │   └── calculate_cost.c
│   └── stack/                  # Gestion des piles
│       ├── stack_init.c
│       ├── stack_utils.c
│       ├── stack_exit.c
│       └── parse_arg.c
├── push_swap_tester/           # Testeur de performance
├── push_swap_visualizer/       # Visualiseur graphique
└── checker_linux              # Vérificateur fourni par 42
```

## 📦 Installation

```bash
# Cloner le repository
git clone https://github.com/votre-username/push_swap.git
cd push_swap

# Compiler le projet
make

# Compiler avec les outils de test (optionnel)
make -C push_swap_tester en    # ou 'fr' pour le français
```

## 🚀 Utilisation

### Utilisation basique
```bash
# Trier une liste de nombres
./push_swap 3 2 5 4 1

# Avec une chaîne de caractères
./push_swap "3 2 5 4 1"

# Vérifier le tri avec checker
./push_swap 3 2 5 4 1 | ./checker_linux 3 2 5 4 1
```

### Tests automatisés
```bash
# Test avec 2 éléments
make test2

# Test avec 3 éléments  
make test3

# Test avec 5 éléments
make test5

# Test avec 100 éléments
make test100

# Test avec 500 éléments
make test500
```

### Testeur de performance
```bash
# Tester 100 éléments, 100 fois
./push_swap_tester/complexity 100 100

# Avec objectif de performance (ex: <700 opérations pour 100 éléments)
./push_swap_tester/complexity 100 100 700 ./checker_linux
```

### Visualiseur graphique
```bash
cd push_swap_visualizer
mkdir build && cd build
cmake ..
make
./bin/visualizer
```

## 🧮 Algorithme

Le projet utilise une approche hybride :

1. **Tri simple** (≤5 éléments) : Algorithme optimisé pour les petites tailles
2. **Tri avancé** (>5 éléments) : Algorithme basé sur le calcul de coût minimal
   - Pousse les éléments vers la pile B sauf les 3 derniers
   - Trie les 3 éléments restants dans A
   - Calcule le coût pour remettre chaque élément de B dans A
   - Choisit l'élément avec le coût minimal à chaque itération

## 📊 Performance attendue

| Taille | Instructions max | Objectif recommandé |
|--------|------------------|-------------------|
| 3      | 3                | ≤ 3               |
| 5      | 12               | ≤ 12              |
| 100    | -                | ≤ 700             |
| 500    | -                | ≤ 5500            |

## 🔍 Gestion d'erreurs

Le programme gère les cas d'erreur suivants :
- Arguments non numériques
- Débordement d'entiers (dépassement de `INT_MAX` ou `INT_MIN`)
- Doublons dans la liste
- Liste vide ou arguments manquants

En cas d'erreur, le programme affiche `Error` sur la sortie d'erreur et se termine avec un code d'erreur.

## 🛠️ Outils inclus

### Push Swap Tester
Testeur de performance développé par la communauté 42 pour évaluer l'efficacité de l'algorithme.

### Push Swap Visualizer  
Visualiseur graphique permettant de voir l'exécution de l'algorithme en temps réel.

## 📝 Fonctions principales

- `init_stack` : Initialisation de la pile depuis les arguments
- `sort_stack` : Point d'entrée de l'algorithme de tri
- `advanced_sort` : Algorithme de tri pour les grandes listes
- `calculate_cost` : Calcul du coût minimal pour les opérations
- `free_stack` : Libération de la mémoire de la pile
- `exit_cleanup` : Nettoyage en cas d'erreur

## 🏫 Projet 42

Ce projet fait partie du cursus de l'école 42. Il permet d'approfondir :
- Les algorithmes de tri
- La gestion de la mémoire en C
- L'optimisation d'algorithmes
- La manipulation de structures de données (listes chaînées)

## 🔗 Ressources utiles

- [Push Swap Tester](https://github.com/LeoFu9487/push_swap_tester)
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Sujet du projet](https://projects.intra.42.fr/projects/push_swap)

## 📄 Licence

Ce projet est réalisé dans le cadre du cursus de l'école 42.

---

**Note :** N'hésitez pas à contribuer en créant des issues ou des pull requests pour améliorer le code ou la documentation !
