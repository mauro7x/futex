# futex
Investigación y pruebas sobre el comportamiento de la syscall **futex** como parte del trabajo práctico final para Sistemas Operativos, materia de la carrera Ingeniería en Informática dictada en la Facultad de Ingeniería, Universidad de Buenos Aires.

## Detalles administrativos
* Autor: Mauro Parafati
* Padrón: 102749
* Mail: mparafati@fi.uba.ar
* Materia: Sistemas Operativos

## Bibliografía general
* [man](https://man7.org/linux/man-pages/man2/futex.2.html)
* [wikipedia](https://en.wikipedia.org/wiki/Futex)

### Bibliografía (dirección: userspace)
*(Los articulos chequeados representan que ya fueron leídos)*

#### Articulos
- [x] [Basics of Futexes](https://eli.thegreenplace.net/2018/basics-of-futexes)
- [x] [A futex overview and update](https://lwn.net/Articles/360699/)
- [ ] [FUTEX_SWAP (nueva primitiva)](https://lwn.net/Articles/826860/)

#### Papers (userspace)
- [x] [Fuss, Futexes and Furwocks: Fast Userlevel Locking in Linux](docs/userspace/Fuss_Futexes_and_Furwocks_Fast_Userlevel_Locking_in_Linux.pdf)
- [x] [Futexes Are Tricky](docs/userspace/Futexes_are_Tricky.pdf)
- [x] [Futex based locks for C11's generic atomics (extended abstract)](docs/userspace/Futex_based_locks_for_C11s_generic_atomics.pdf)

### Bibliografía (dirección: kernel)

#### Libros
- [ ] [Synchronization primitives (Linux Insides)](https://0xax.gitbooks.io/linux-insides/content/SyncPrim/)

#### Videos
- [ ] [The Multicore Evolution and Operating Systems](https://www.youtube.com/watch?v=Ht6UPeQtFgo&ab_channel=uwaterloo)

#### Papers
- [ ] [Non-scalable locks are dangerous](docs/kernel/Non_scalable_locks_are_dangerous.pdf) *(vinculado con el video "The Multicore Evolutio nand Operating Systems")*

#### Slides
- [ ] [SMP, Multicore, Memory Ordering & Locking](docs/kernel/05-smp_locking.pdf)
    - [ ] [Programa del curso completo](https://www.cse.unsw.edu.au/~cs9242/20/lectures.shtml)
