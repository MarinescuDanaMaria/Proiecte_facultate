#!/bin/bash


fisier_csv="fisier_inregistrari.csv"


creare_fisier_CSV()
 {

        if [[ -f "$fisier_csv" ]]

        then

                echo "Fisierul a fost creat anterior!"

        else 

                echo "Fisierul a fost creat cu succes."

        fi

 }


ID_maxim()
 {

        max=$(tail -n +1 "$fisier_csv" | cut -d ',' -f1 | sort -n | tail -n 1)

        echo "$max"

 }


populare_fisier_CSV()
 {

       valid=false

       while [ "$valid" = false ]

       do

       read -p "Introduceti numarul de inmatriculare: " numar

       if [[ $numar =~ ^[A-Z]{1,2}[0-9]{1,2}[A-Z]{3}$ ]]; then

       valid=true

       echo "Numarul de inmatriculare este corect."

       else

       echo "Ati introdus gresit numarul de inmatriculare. Va rugam sa incercați din nou."

       fi

       done

       echo "Alegeti tipul autoturismului:"
       echo "1. autoturism"
       echo "2. motocicleta"
       echo "3. autoutilitara"
       echo "4. scuter"
       echo "5. moped"
       echo "6. ATV"
       echo "7. microbuz"
       echo "8. autoturism de teren"

       valid=false

       while [ "$valid" = false ]

       do

       read -p "Alegeti o optiune: " optiune

       case $optiune in

        1)
            tip="autoturism"
            echo "Ati ales autoturism."
            valid=true
            ;;

        2)
            tip="motocicleta"
            echo "Ati ales motocicleta."
            valid=true
            ;;

        3)
            tip="autoutilitara"
            echo "Ati ales autoutilitara."
            valid=true
            ;;

        4)
            tip="scuter"
            echo "Ati ales scuter."
            valid=true
            ;;

        5)
            tip="moped"
            echo "Ati ales moped."
            valid=true
            ;;

        6)
            tip="ATV"
            echo "Ati ales ATV."
            valid=true
            ;;

        7)
            tip="microbuz"
            echo "Ati ales microbuz."
            valid=true
            ;;

        8)
            tip="autoturism de teren"
            echo "Ati ales autoturism de teren."
            valid=true
            ;;

        *)
            echo "Optiune invalida. Va rugam să alegeti din nou."
            ;;

        esac

        done

        echo "Alegeti tipul combustibilului:"
        echo "1. benzina"
        echo "2. hybrid"
        echo "3. diesel"
        echo "4. electrica"
        echo "5. GPL"
        echo "6. hidrogem"

        valid=false

        while [ "$valid" = false ]

        do

        read -p "Alegeti o opțiune: " varianta

        case $varianta in

        1)
            mot="benzina"
            echo "Ati ales benzina."
            valid=true
            ;;
        2)
            mot="hybrid"
            echo "Ati ales hybrid."
            valid=true
            ;;
        3)
            mot="diesel"
            echo "Ati ales diesel."
            valid=true
            ;;
        4)
            mot="electrica"
            echo "Ati ales electrica."
            valid=true
            ;;
        5)
            mot="GPL"
            echo "Ati ales GPL."
            valid=true
            ;;
        6)
            mot="hidrogen"
            echo "Ati ales hidrogen."
            valid=true
            ;;
        *)
            echo "Optiune invalida. Va rugam sa alegeti din nou."
            ;;

        esac

        done

        read -p "Introduceti marca auto: " marca

        valid=false

        while [ "$valid" = false ]

        do

        read -p "Introduceti anul de fabricatie: " an

        if [[ "$an" =~ ^[1-9][0-9][0-9][0-9]$ ]]; then

        valid=true

        else

        echo "Anul introdus este invalid. Va rugam sa introduceti un an format din patru cifre."

        fi

        done

        valid=false

        while [ "$valid" = false ]

        do

        read -p "Introduceti capacitatea cilindrica: " cc

        if [[ "$cc" =~ ^[1-9][0-9]{2,3}$ ]]; then

        valid=true

        else

        echo "Capacitate cilindrica introdusa gresit. Va rugam sa incercati din nou."

        fi

        done

        valid=false

	while [ "$valid" = false ]

        do

	read -p "Introduceti varsta dumneavoastra: " vst

	if [[ "$vst" =~ ^[1-9][0-9]{1,2}$ ]]; then

        valid=true

	else

        echo "Varsta introdusa gresit. Va rugam sa incercati din nou."

	fi

        done

        cost_final=0

        if  [ $vst -le 30 ] && [ $cc -le 1200 ]; then

        cost_final=1822

        elif [ $vst -le 30 ] && [ $cc -ge 1201 ] && [ $cc -le 1400 ]; then

        cost_final=1931

        elif [ $vst -le 30 ] && [ $cc -ge 1401 ] && [ $cc -le 1600 ]; then

        cost_final=2187

        elif [ $vst -le 30 ] && [ $cc -ge 1601 ] && [ $cc -le 1800 ]; then

        cost_final=2327

        elif [ $vst -le 30 ] && [ $cc -ge 1801 ] && [ $cc -le 2000 ]; then

        cost_final=2502

        elif [ $vst -le 30 ] && [ $cc -ge 2001 ] && [ $cc -le 2500 ]; then

        cost_final=3304

        elif [ $vst -le 30 ] && [ $cc -ge 2501 ]; then

        cost_final=4709

        elif [ $vst -ge 31 ] && [ $vst -le 40 ] && [ $cc  -le 1200 ]; then

        cost_final=1114

        elif [ $vst -ge 31 ] && [ $vst -le 40 ] && [ $cc -ge 1201 ] && [ $cc -le 1400 ]; then

        cost_final=1123

        elif [ $vst -ge 31 ] && [ $vst -le 40 ] && [ $cc -ge 1401 ] && [ $cc -le 1600 ]; then

        cost_final=1236

        elif [ $vst -ge 31 ] && [ $vst -le 40 ] && [ $cc -ge 1601 ] && [ $cc -le 1800 ]; then

        cost_final=1364

        elif [ $vst -ge 31 ] && [ $vst -le 40 ] && [ $cc -ge 1801 ] && [ $cc -le 2000 ]; then

        cost_final=1481

        elif [ $vst -ge 31 ] && [ $vst -le 40 ] && [ $cc -ge 2001 ] && [ $cc -le 2500 ]; then

        cost_final=1972

        elif [ $vst -ge 31 ] && [ $vst -le 40 ] && [ $cc -ge 2501 ]; then

        cost_final=2832

        elif [ $vst -ge 41 ] && [ $vst -le 60 ] && [ $cc  -le 1200 ]; then

        cost_final=1076

        elif [ $vst -ge 41 ] && [ $vst -le 60 ] && [ $cc -ge 1201 ] && [ $cc -le 1400 ]; then

        cost_final=1129

        elif [ $vst -ge 41 ] && [ $vst -le 60 ] && [ $cc -ge 1401 ] && [ $cc -le 1600 ]; then

        cost_final=1265

        elif [ $vst -ge 41 ] && [ $vst -le 60 ] && [ $cc -ge 1601 ] && [ $cc -le 1800 ]; then

        cost_final=1356

        elif [ $vst -ge 41 ] && [ $vst -le 60 ] && [ $cc -ge 1801 ] && [ $cc -le 2000 ]; then

        cost_final=1445

        elif [ $vst -ge 41 ] && [ $vst -le 60 ] && [ $cc -ge 2001 ] && [ $cc -le 2500 ]; then

        cost_final=1974

        elif [ $vst -ge 41 ] && [ $vst -le 60 ] && [ $cc -ge 2501 ]; then

        cost_final=2912

        elif [ $vst -gt 60 ] && [ $cc  -le 1200 ]; then

        cost_final=1036

        elif [ $vst -gt 60 ] && [ $cc -ge 1201 ] && [ $cc -le 1400 ]; then

        cost_final=1079

        elif [ $vst -gt 60 ] && [ $cc -ge 1401 ] && [ $cc -le 1600 ]; then

        cost_final=1204

        elif [ $vst -gt 60 ] && [ $cc -ge 1601 ] && [ $cc -le 1800 ]; then

        cost_final=1325

        elif [ $vst -gt 60 ] && [ $cc -ge 1801 ] && [ $cc -le 2000 ]; then

        cost_final=1392

        elif [ $vst -gt 60 ] && [ $cc -ge 2001 ] && [ $cc -le 2500 ]; then

        cost_final=1966

        elif [ $vst -gt 60 ] && [ $cc -ge 2501 ]; then

        cost_final=2767

        fi

        echo "Costul final al asigurării RCA este: $cost_final lei."

        echo "Cam scump...Va atasam mai jos ofertele din aceasta saptamana la biciclete"

        echo "https://www.decathlon.ro/browse/c0-toate-sporturile/c1-ciclism/c2-biciclete/_/N-1lxzozt"

        max=$(ID_maxim)

        if [[ -z $max ]]; then

                ID_nou=1

        else

                ID_nou=$((max + 1))

        fi

        echo "$ID_nou,$numar,$tip,$mot,$marca,$an,$cc,$vst,$cost_final" >> "$fisier_csv"

        echo "Datele au fost adaugate in fisier!"

       read -p "Doriți să adăugați o altă înregistrare? (Da/Nu): " opt

       if [[ $opt == "Nu" || $opt == "NU" || $opt == "nu" ]]; then
 
       return

       fi


 }


afisare_fisier_CSV()
 {
        echo "Continutul fisierului CSV:"

        echo "  "

        echo "Id,Nr inmatriculare,Tip,Motorizare,Marca,An,Cc,Vst,Cost final"

        cat "$fisier_csv"

 }

golire_fisier_CSV()
 {

        echo "Esti sigur ca vrei sa golesti fisierul CSV? Aceasta actiune este ireversibila. (Da/Nu)"

        read confirmare

        if [[ $confirmare == "Da" || $confirmare == "DA" || $confirmare == "da" ]]

        then

        > "$fisier_csv"

        echo "Fisierul a fost golit cu succes!"

        else

        echo "Golirea nu s-a putut efectua."

        fi

 }


stergere_din_fisier_CSV()
 {

        echo "Introduceti ID-ul pe care vreti sa il stergeti:"

        read id

        rec=$(awk -F ',' -v id="$id" '($1 == id) {print}' "$fisier_csv")

        if [[ -z $rec ]]

        then echo "Nu exista acest ID"

        else    # creem un fisier temporar

        temp_file="temp.csv"

         awk -F ',' -v id="$id" '($1 != id) {print}' "$fisier_csv" > "$temp_file"

         mv "$temp_file" "$fisier_csv"

         echo "Inregistrarea cu ID-ul $id a fost stearsa."

         "$temp_file"

         >"$temp_file"

         fi

 }


sortare_numereinm()
 {

        sort -t ',' -k2 "$fisier_csv" -o "$fisier_csv"

        echo "Inregistrarile au fost sortate in ordine alfabetica."

 }


sortare_pret_rca()
 {

        sort -t ',' -k9nr "$fisier_csv" -o "$fisier_csv"

        echo "Inregistrarile au fost sortate in ordine descrescatoare."

 }

afisare_primele_3_inregistrari()
 {
    echo "Primele trei înregistrări sortate:"
    head -n 3 "$fisier_csv"
 }

modif_inreg()
 {

        echo "Introduceti ID-ul inregistrarii pe care vreti sa o modificati:"

        read id

        rec=$(awk -F ',' -v id="$id" '($1 == id) {print}' "$fisier_csv")

        if [[ -z $rec ]]

        then echo "Nu exista acest ID"

        else

        echo "Introduceți noile valori pentru înregistrare:"

        read noi_valori

        regex="^($id,[^,],[^,],[^,],[^,],[^,],[^,],[^,],)([^,])(,.*)$"

        sed -i "s/$regex/\1$noi_valori\3/" "$fisier_csv"

        echo "Înregistrarea cu ID-ul $id a fost actualizată cu succes."

        fi

 }


      #meniu:

       i=1

       while [ $i -ne 0 ]

       do

                echo "=================================="
                echo "          MENIU PRINCIPAL         "
                echo "=================================="



                echo



                echo "1. Creare fisier "



                echo "2. Introduceti datele pentru a"
                echo "   afla pretul unei asigurari RCA "



                echo "3. Stergere ID din fisier "



                echo "4. Afisare continut fisier "



                echo "5. Sortare alfabetica a"
                echo "  numerelor de inmatriculare"


                echo "6. Sortare pret RCA "



                echo "7. Golire fisier"



                echo "8. Curatare ecran "



                echo "9. Iesire"

                echo "10. Afiseaza primii 3 clienti "
                echo "cu asigurarea cea mai mare"

                echo "11. Modificare inregistrari "

                echo "=================================="


                read i

                case $i in

                1) creare_fisier_CSV; sleep 5;;


                2) populare_fisier_CSV; sleep 2;;


                3) stergere_din_fisier_CSV; sleep 2;;


                4) afisare_fisier_CSV; sleep 2;;


                5) sortare_numereinm; sleep 2;;


                6) sortare_pret_rca; sleep 2;;


                7) golire_fisier_CSV; sleep 2;;


                8) clear; sleep 2;;


                9) break; sleep 2;;

               10) afisare_primele_3_inregistrari; sleep  2;;

               11) modif_inreg; sleep 2;;

                 *) echo "Optiune invalida!"; sleep 2;;
                esac

                echo " "

                done
