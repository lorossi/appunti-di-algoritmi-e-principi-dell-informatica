# Appunti di Algoritmi e Principi dell'Informatica

Questa repository contiene i gli appunti del corso di Algoritmi e Principi dell'Informatica, relativi al corso tenuto nell'Anno Accademico 2021/2022 al Politecnico di Milano.

Può darsi che questi appunti siano costellati di errori e di dettagli (più o meno grossi) che mi sono sfuggiti.
In quel caso, sentitevi liberi di aprire una pull request, una issue o semplicemente mandarmi una mail!

Vi ringrazio in anticipo per le correzioni.

## Compilazione dei file tramite LaTeX

La compilazione di questi appunti è leggermente problematica a causa dell'uso intensivo della libreria `tikz`:

- **Se usate VScode** insieme al plugin [LaTeX Workshop](https://marketplace.visualstudio.com/items?itemName=James-Yu.latex-workshop) e Python 3.6+ è installato sul sistema, allora non sussiste nessun problema, perché tutte le istruzioni per la compilazione sono all'interno del file `settings.json`
- Se state cercando di compilare via un **qualsiasi altro editor di testo**, dovrete:
  1. Creare una cartella chiamata `tikztemp` all'interno cartella principiale
  2. Creare una copia del file `tikzit.tikzstyles` chiamata `tikzstyle.tikzstyles` che rimuova ogni riferimento a `tikzit` al suo interno
     - questi due passi sono automatizzati dallo script `envsetup.py`, quindi se Python è installato sul sistema sarà possibile usarlo direttamente
  3. Abilitare una flag (`--shell-escape`) sul compilatore
  4. Finalmente compilare usando `latexpdf` perché non ho provato altri compilatori

La prima compilazione, indipendentemente da quale metodo viene usato, potrebbe richiedere molto tempo perché tutte le immagini devono essere pre-generate.

## Licensing

These notes are distributed under Creative Commons 4.0 license.
