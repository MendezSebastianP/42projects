#!/bin/bash

# Parcourt tous les fichiers .c dans le dossier courant
for file in *.c; do
    # Sauvegarde le contenu original du fichier pour une manipulation sûre
    cp "$file" "$file.bak"

    # Traite chaque fichier ligne par ligne
    awk 'NR < 12 { print; next } { 
        gsub(/ {4}/, "\t"); print 
    }' "$file.bak" > "$file"

    # Supprime le fichier de sauvegarde si tout est correct
    rm "$file.bak"
done
