/*

    Zelda Return of the Hylian

    Copyright (C) 2005-2008  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#include "os_3ds.h"

#include "Texte.h"
#include "Menu.h"
#include "Joueur.h"
#include "Monde.h"
#include "Projectile.h"
#include "Jeu.h"
#include "3ds/gfx_3ds.h"

Texte::Texte(Jeu* jeu) : gpJeu(jeu), vitesse(40), av(0), x(0), y(0), w(0), h(0),
id(0), idsuiv(0), def(false), cadre(false), texte(""), buffer(""), buffer2("") {
    lastAnimTime = SDL_GetTicks();
    imageFont = IMG_Load("romfs:/images/texte/font.png");
    SDL_SetColorKey(imageFont,SDL_SRCCOLORKEY,SDL_MapRGB(imageFont->format,0,0,255));
    imageCoeur = IMG_Load("romfs:/images/menu/coeur.png");
    SDL_SetColorKey(imageCoeur,SDL_SRCCOLORKEY,SDL_MapRGB(imageCoeur->format,0,0,255));
}

Texte::~Texte() {
    SDL_FreeSurface(imageFont);
    SDL_FreeSurface(imageCoeur);
}

void Texte::chercheText() {
    ostringstream os;
    int tmp;
	
switch(getLanguage()) {

case 2: // French

    switch (id) {
        case 1  : texte = "Tu as trouv� un bouclier !!!**Ta d�fense augmente d'un point !"; break;
        case 2  : texte = "Tu as trouv� une �p�e !!!**Tu vas pouvoir te d�fendre face aux monstres avec la touche B !!!*Maintiens B enfonc� pour charger une attaque cyclone !!!"; break;
        case 3  : 
            tmp = 4-(gpJeu->getJoueur()->nbQuarts()%4);
            os << tmp;
            texte = "Tu as trouv� un quart de coeur !!!";
            if (tmp<4) buffer = "Encore "+os.str()+" et tu gagneras un coeur suppl�mentaire !!!";
            else buffer = "Ton nombre de coeurs vient d'augmenter !!!";
            break;
        case 11 : texte = "N : Maison de Link*O : Plaine d'Hyrule*E : Temple de la For�t"; break;
        case 12 : texte = "Temple de la Montagne**D�conseill� aux cardiaques, peureux, et aux �mes sensibles en g�n�ral."; break;
        case 13 : texte = "O : Entr�e du D�sert*N : Temple de la Montagne"; break;
        case 14 : texte = "N : Temple de la Montagne*S : Plaine d'Hyrule"; break;
        case 15 : texte = "N : Mont du P�ril"; break;
        case 16 : texte = "E : Entr�e de la For�t"; break;
        case 17 : texte = "S : Lac Hylia*E : Cimeti�re Hant�"; break;
        case 18 : texte = "S : Vers le Village Cocorico"; break;
        case 19 : texte = "N : Village Cocorico"; break;
        case 20 : texte = "N : Plaine d'Hyrule"; break;
        case 21 : texte = "O : Terres de Feu"; break;
        case 22 : texte = "E : Village de l'Ombre*- D�conseill� aux vivants -"; break;
        case 23 : texte = "Temple des T�n�bres**Si vous �tes un fant�me et que vous cherchez un job, venez plut�t ch�mer ici."; break;
        case 24 : texte = "N : Village de l'Ombre*O : Lac Hylia"; break;
        case 25 : texte = "N : Cimeti�re Hant�**Entr�e interdite"; break;
        case 26 : texte = "Village de l'Ombre"; break;
        case 27 : texte = "Je vends un flacon pour 100 rubis, �a t'int�resse ?*              OUI ?            non  "; 
            if ((gpJeu->getJoueur()->hasBouteille(0) && gpJeu->getZone()==8)
            || (gpJeu->getJoueur()->hasBouteille(1) && gpJeu->getZone()==5)
            || (gpJeu->getJoueur()->hasBouteille(2) && gpJeu->getZone()==6)) {id=32; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<100) idsuiv=29;
            else idsuiv=30;
            break;
        case 28 : texte = "Je vends un flacon pour 100 rubis, �a t'int�resse ?*              oui              NON ?"; idsuiv=31; break;
        case 29 : texte = "D�sol�, mais tu n'as pas assez de rubis."; break;
        case 30 : texte = "Merci beaucoup, voil� ton flacon."; break;
        case 31 : texte = "Reviens me voir si tu changes d'avis."; break;
        case 32 : texte = "D�sol�, c'�tait mon seul flacon."; break;
        case 33 : texte = "Tu as trouv� un flacon vide !!!**Tu vas pouvoir t'en servir pour stocker des potions !!!"; break;
        case 35 : texte = "Les habitants de ce village ont un dialecte tr�s particulier, je n'y comprends rien..."; break;
        case 36 : texte = "@+@+@+@+@+@+@@@+*@=++=@=+@=+@=+=@*+@+@+@+=+="; break;
        case 37 : texte = "Obtiens une autorisation du chef si tu veux vraiment passer!!!"; break;
        case 38 : texte = "Le chef t'as autoris� � passer ??? Grrrr... Alors �carte toi!!!"; break;
        case 39 : texte = "Ne tra�ne pas dans mes pattes !!!"; break;
        case 40 : texte = "On n'a pas l'habitude de voir des visiteurs par ici..."; break;
        case 41 : texte = "Les monstres du coin ne craignent pas grand chose, heureusement qu'ils n'attaquent que les humains."; break;
        case 42 : texte = "C'est vrai ?*Tu comprends ce que je dis ?"; break;
        case 43 : texte = "N : D�sert et Village Gerudo"; break;
        case 44 : texte = "S : Lac Hylia*O : Ch�teau d'Hyrule"; break;
        case 45 : texte = "Village Cocorico"; break;
        case 46 : texte = "O : Ch�teau d'Hyrule"; break;
        case 47 : texte = "Quelle belle journ�e !!!"; break;
        case 48 : texte = "Pourquoi ai-je accept� de m'occuper de ces salet�s ???*J'ai horreur des poules !!!"; break;
        case 49 : texte = "On trouve des tas de choses dans les boutiques du village."; break;
        case 50 : texte = "S : Village Cocorico*O : D�sert*E : Mont du P�ril"; break;
        case 51 : texte = "Village Gerudo"; break;
        case 52 : texte = "Perdu dans le d�sert ?*Vous �tes ici :*                        X"; break;
        case 54 : texte = "S : Vers le Ch�teau d'Hyrule"; break;
        case 55 : texte = "Temple du D�sert**Venez essayer nos bains.*(eau non-potable)"; break;
        case 56 : texte = "Temple de la For�t**Sauvez les arbres, mangez du castor!!!"; break;
        case 57 : texte = "Temple du Lac**Bonnet de bain obligatoire."; break;
        case 58 : texte = "Temple de Glace**Le personnel tient � rappeler qu'un donjon n'est pas une patinoire."; break;
        case 59 : texte = "As-tu �t� voir le forgeron de ce village ?*On dit qu'il est tr�s dou� pour am�liorer l'�quipement des aventuriers, beaucoup de monde lui rend visite."; break;
        case 60 : texte = "Le temple se trouve au fin fond du d�sert, � la place d'une ancienne oasis."; break;
        case 61 : texte = "S : Terres de Feu*E : Village Cocorico"; break;
        case 62 : texte = "Ch�teau d'Hyrule"; break;
        case 63 : texte = "E : Village Cocorico"; break;
        case 64 : texte = "O : Roc de la Tortue*E : Lac Hylia"; break;
        case 65 : texte = "Temple Cach�**Ici repose la lame purificatrice, Excalibur."; break;
        case 66 : texte = "N : Vers le cimeti�re hant�"; break;
        case 67 : texte = "Tu as trouv� la carte du donjon !!!*Appuie sur START pour voir le plan."; break;
        case 68 : texte = "Tu as trouv� la boussole !!!*Tu peux localiser le boss et les coffres sur le plan."; break;
        case 69 : texte = "Tu as trouv� la cl� du boss !!!"; break;
        case 70 : texte = "Tu as trouv� une petite cl� !!!*Approche une porte pour l'ouvrir."; break;
        case 71 : texte = "Tu as trouv� les gants !!!*Utilise-les pour soulever des objets en les �quipant ou en appuyant sur X."; break;
        case 72 : 
            texte = "Tu as trouv� un cristal magique !!!"; 
            tmp = 7-gpJeu->getJoueur()->nbCristaux();
            os << tmp;
            if (tmp==6 && !gpJeu->getJoueur()->getAvancement()) buffer = "A quoi pourra-t-il bien servir ?";
            else if (tmp>2) buffer = "Il en reste encore "+os.str()+" � trouver !!!";
            else if (tmp==2) buffer = "Plus que 2 � trouver !!!";
            else if (tmp==1) buffer = "Il ne t'en manque plus qu'un seul !!!";
            else if (tmp==0) buffer = "Tu as tous les cristaux, cours au ch�teau sauver Zelda !!!";
            break;
        case 80 : texte = "Tu as trouv� le grappin !!!*Utilise-le pour franchir des obstacles."; break;
        case 81 : texte = "Tu as trouv� la lanterne !!!*Utilise-la pour faire jaillir des flammes."; break;
        case 82 : texte = "Tu as trouv� les palmes !!!*Equipe-les pour aller dans l'eau."; break;
        case 83 : texte = "Tu as trouv� le marteau magique !!!*Utilise-le pour �craser les obstacles."; break;
        case 84 : texte = "Tu as trouv� le baton de feu !!!*Tu peux d�sormais lancer de puissantes flammes � distance."; break;
        case 85 : texte = "Tu as trouv� le baton de glace !!!*Utilise-le pour tout congeler � distance."; break;
        case 86 : texte = "Tu as trouv� Excalibur !!!*M�me Ganon ne devrait pas pouvoir r�sister � sa puissance !!! (en th�orie)"; break;
        case 87 : texte = "F�licitation Link, tu as r�ussi � venir me d�livrer!!!***Allons vite trouver Ganon, il faut imp�rativement lui reprendre la Triforce !"; break;
        case 89 : texte = "Le passage secret derri�re la salle du tr�ne m�ne � Ganon. D�p�chons-nous !"; break;
        case 90 : texte = "Nous y sommes presque, suis-moi !"; break;
        case 91 : texte = "J'ai bien peur que tu ne puisses jamais vaincre Ganon avec tes armes actuelles...*Va parler au chef du village Cocorico, je suis s�re qu'il trouvera une solution."; break;
        case 92 : texte = "Ganon est juste derri�re cette porte, je vais soigner tes blessures."; break;
        case 93 : texte = "Ganon est toujours quelque part dans le ch�teau."; break;
        case 94 : texte = "Tu devrais attendre la princesse Zelda !!!"; break;
        case 95 : texte = "Tu n'aurais pas l'�trange sentiment d'oublier quelqu'un par hasard ???"; break;
        case 96 : texte = "Zelda t'attend!!!"; break;
        case 97 : texte = "Tu as trouv� la Triforce!!!"; break;
        case 98 : texte = "Tu as trouv� le livre de Mudora!!!**Tu comprends d�sormais le Hylien ancien!!!"; break;
        case 99 : texte = "F�licitation Link, tu as r�ussi � me trouver. En r�compense, je t'offre le m�daillon de Din, il augmente ta d�fense d'un point."; break;
        case 100 : texte = "F�licitation Link, tu as r�ussi � me trouver. En r�compense, je t'offre le m�daillon de Nayru, il augmente ta d�fense de deux points!!!"; break;
        case 101 : texte = "..."; break;
        case 102 : texte = "Tu as obtenu un m�daillon magique !!!**Ta d�fense vient d'augmenter!!!"; break;
        case 103 : texte = "F�licitation Link, tu as r�ussi � me trouver. Pour te r�compenser, je vais doubler la capacit� de ta r�serve de magie!!!"; break;
        case 104 : texte = "Ta r�serve de magie a doubl�!!!"; break;
        case 105 : texte = "Reviens me voir quand tu auras un flacon vide  et je te vendrai une potion rouge qui restaure l'�nergie."; break;
        case 106 : texte = "Une potion rouge pour 60 rubis, �a t'int�resse?*              OUI ?            non  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=105; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<60) idsuiv=29;
            else idsuiv=108; break;
        case 107 : texte = "Une potion rouge pour 60 rubis, �a t'int�resse?*              oui              NON ?"; break;
        case 108 : texte = "Merci, voil� ta potion.";break;
        case 109 : texte = "Tu as obtenu une potion rouge !!!*Bois-la pour restaurer ton �nergie!!!"; break;
        case 110 : texte = "Tu as obtenu une potion verte !!!*Bois-la pour restaurer ta magie!!!"; break;
        case 111 : texte = "Tu as obtenu une potion bleue !!!*Bois-la pour restaurer ton �nergie et ta magie!!!"; break;
        case 112 : texte = "Bonjour, je vous sers quelque chose ?"; break;
        case 113 : texte = "Hic! On raconte qu'une f�e donnerait des objets enchant�s... Hic! ...aux aventuriers qui la  trouveraient... Hic!!!"; break;
        case 114 : texte = "Un coeur pour 10 rubis, ok ?**              OUI ?            non  "; 
            if (gpJeu->getJoueur()->getVie()+gpJeu->getJoueur()->getBoostVie()
            == gpJeu->getJoueur()->getVieMax()) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29;
            else idsuiv=129; break;
        case 115 : texte = "Un coeur pour 10 rubis, ok ?**              oui              NON ?"; break;
        case 116 : texte = "Un peu de magie pour 20 rubis, ok ?**              OUI ?            non  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<20) idsuiv=29;
            else idsuiv=129; break;
        case 117 : texte = "Un peu de magie pour 20 rubis, ok ?**              oui              NON ?"; break;
        case 118 : texte = "Beaucoup de magie pour 30 rubis, ok ?**              OUI ?            non  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 119 : texte = "Beaucoup de magie pour 30 rubis, ok ?**              oui              NON ?"; break;
        case 120 : texte = "5 fl�ches pour 30 rubis, ok ?**              OUI ?            non  "; 
            if (gpJeu->getJoueur()->getFleche() == gpJeu->getJoueur()->getFlecheMax() 
            || !gpJeu->getJoueur()->hasObjet(O_ARC)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 121 : texte = "5 fl�ches pour 30 rubis, ok ?**              oui              NON ?"; break;
        case 122 : texte = "Une bombe pour 30 rubis, ok ?**              OUI ?            non  "; 
            if (gpJeu->getJoueur()->getBombe() == gpJeu->getJoueur()->getBombeMax() 
            || !gpJeu->getJoueur()->hasObjet(O_SAC_BOMBES)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 123 : texte = "Une bombe pour 30 rubis, ok ?**              oui              NON ?"; break;
        case 124 : texte = "Un arc pour 1000 rubis, ok ?**              OUI ?            non  "; 
            idsuiv=29; break;
        case 125 : texte = "Un arc pour 1000 rubis, ok ?**              oui              NON ?"; break;
        case 126 : texte = "Un arc pour 50 rubis, ok ?**              OUI ?            non  "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<50) idsuiv=29;
            else idsuiv=129; break;
        case 127 : texte = "Un arc pour 50 rubis, ok ?**              oui              NON ?"; break;
        case 128 : texte = "Tu n'as pas besoin de �a maintenant."; break;
        case 129 : texte = "Merci."; break;
        case 130 : texte = "Tu as obtenu l'arc !!!*Utilise-le pour atteindre des cibles �loign�es."; break;
        case 131 : texte = "Choisis ce que tu veux."; break;
        case 132 : texte = "Hein ???*Tu es en mission pour le chef ???*Bon alors je vais te faire une r�duction sur l'arc..."; break;
        case 133 : texte = "Bonjour Link, je suis le chef de ce village, je me doutais que tu passerais."; idsuiv=134; break;
        case 134 : texte = "Depuis ce matin des monstres sont apparus un peu partout � Hyrule, j'ai voulu aller en parler � la princesse Zelda, mais comme tu l'as peut-�tre d�j� vu, un puissant sortil�ge bloque l'acc�s au ch�teau..."; idsuiv=136; break;
        case 136 : texte = "Tu dis que Ganon est responsable de tout �a ? Qu'il a vol� la Triforce et qu'il d�tient la princesse Zelda prisonni�re ?"; idsuiv=137; break;
        case 137 : texte = "Mmmm... la situation est plus grave que je le croyais..."; idsuiv=138; break;
        case 138 : texte = "Il faut agir au plus vite, tu dois affronter Ganon � nouveau!"; idsuiv=139; break;
        case 139 : texte = "Comment entrer dans le ch�teau ? J'ai peut-�tre une id�e..."; idsuiv=140; break;
        case 140 : texte = "Comme tu le sais, le pouvoir des 7 sages a �t� enferm� dans 7 cristaux par le sorcier Aghanim alors qu'il tentait de lever le sceau qui confinait Ganon au monde des t�n�bres."; idsuiv=141; break;
        case 141 : texte = "Or, bien que tu aies ressuscit� les descendants des sages apr�s avoir vaincu Ganon et trouv� la Triforce, ces cristaux ont conserv� leur puissance."; idsuiv=142; break;
        case 142 : texte = "Ils ont �t� cach�s au fin fond des 7 temples, r�unis-les tous et tu pourras passer outre le sortil�ge de Ganon."; idsuiv=143; break;
        case 143 : texte = "Ce ne sera toutefois pas chose ais�, Ganon a certainement d� envoyer ses meilleurs �l�ments prot�ger ces cristaux..."; idsuiv=144; break;
        case 144 : texte = "Une derni�re chose, tu n'iras pas loin avec ton �quipement actuel. Va voir le marchand d'armes et dis-lui que tu viens de ma part. Il fera s�rement un geste pour toi."; break;
        case 145 : texte = "Va voir le marchand d'armes et dis-lui que tu viens de ma part, il fera certainement un geste pour toi."; break;
        case 146 : texte = "Il te faut rassembler les 7 cristaux pour avoir une chance de sauver Zelda et Hyrule..."; break;
        case 147 : texte = "Tu as trouv� les 7 cristaux ? Alors rends-toi au ch�teau, tu dois avant tout d�livrer la princesse, elle saura mieux que moi comment sauver Hyrule."; break;
        case 148 : texte = "Tes armes sont sans effet sur Ganon ? Dans ce cas tu dois trouver Excalibur. On raconte qu'elle a �t� dissimul�e dans un temple cach�.*On dit aussi que le chemin menant � la lame purificatrice passe par un village peupl� de monstres...*Je me demande si un tel village existe..."; break;
        case 150 : texte = "Toutefois j'ai bien peur que ton �quipement actuel soit insuffisant pour acc�der � ce temple, tu devrais peut-�tre passer voir le forgeron du village Gerudo..."; break;
        case 151 : texte = "Il est temps d'affronter Ganon et de lui reprendre la Triforce!"; break;
        case 152 : texte = "Hey! Il faut payer pour ouvrir un de mes coffres!!!"; break;
        case 153 : texte = "Un de ces coffres contient un quart de coeur, tu veux tenter ta chance pour 10 rubis ?*Tu ne pourras ouvrir qu'un seul coffre, ok ?*              OUI ?            non  "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29; break;
        case 154 : texte = "Un de ces coffres contient un quart de coeur, tu veux tenter ta chance pour 10 rubis ?*Tu ne pourras ouvrir qu'un seul coffre, ok ?*              oui              NON ?"; break;
        case 155 : texte = "Choisis un coffre."; break;
        case 156 : texte = "Je n'ai plus de prix � mettre en jeu, d�sol�."; break;
        case 157 : texte = "Perdu! Ce coffre est vide."; break;
        case 158 : texte = "Bonjour! Si vous �tes venu voir le forgeron, il habite un peu plus loin."; break;
        case 159 : texte = "Bonjour Link, je suis le chef de ce village.*Tu devrais aller voir le forgeron et lui pr�senter ce que tu veux qu'il reforge dans ton �quipement.";
            buffer = "J'ai �t� inform� de ta qu�te, alors je me suis arrang� avec lui.*Tout sera gratuit pour toi."; break;
        case 160 : texte = "Tu n'as pas besoin de boire cette potion maintenant."; break;
        case 161 : texte = "Une potion verte pour 40 rubis, �a t'int�resse?*              OUI ?            non  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=163; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<40) idsuiv=29;
            else idsuiv=108; break;
        case 162 : texte = "Une potion verte pour 40 rubis, �a t'int�resse?*              oui              NON ?"; break;
        case 163 : texte = "Reviens me voir quand tu auras un flacon vide et je te vendrai une potion verte qui restaure la magie."; break;
        case 164 : texte = "Reviens plus tard, je suis d�bord�!"; break;
        case 165 : texte = "Puis-je faire quelque chose pour toi ?";
            if (gpJeu->getJoueur()->getEpee()==1) {id=166; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_GANTS)==1 && gpJeu->getJoueur()->getObjet()==8) {
                id=169; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_ARC)==2 && gpJeu->getJoueur()->getObjet()==0 
            && gpJeu->getJoueur()->nbCristaux()==7) {
                id=172; chercheText();break;}
            break;
        case 166 : texte = "Veux-tu que je reforge ton �p�e ?**              OUI ?            non  "; break;
        case 167 : texte = "Veux-tu que je reforge ton �p�e ?**              oui              NON ?"; break;
        case 168 : texte = "Ton �p�e a tripl� de puissance et peut d�sormais renvoyer certaines attaques magiques, trop bien !!!*"; break;
        case 169 : texte = "Veux-tu que j'am�liore tes gants ?**              OUI ?            non  "; break;
        case 170 : texte = "Veux-tu que j'am�liore tes gants ?**              oui              NON ?"; break;
        case 171 : texte = "La puissance de tes gants va te permettre de soulever de lourds rochers."; break;
        case 172 : texte = "Veux-tu que j'am�liore ton arc ?**              OUI ?            non  "; break;
        case 173 : texte = "Veux-tu que j'am�liore ton arc ?**              oui              NON ?"; break;
        case 174 : texte = "Ton arc tire d�sormais des fl�ches d'argent d'une puissance d�vastatrice!!!"; break;
        case 175 : texte = "Reviens me voir quand tu auras un flacon vide et je te vendrai une potion bleue qui restaure l'�nergie et la magie."; break;
        case 176 : texte = "Une potion bleue pour 160 rubis, �a t'int�resse?*              OUI ?            non  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=175; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<160) idsuiv=29;
            else idsuiv=108; break;
        case 177 : texte = "Une potion bleue pour 160 rubis, �a t'int�resse?*              oui              NON ?"; break;
        case 178 : texte = "Notre village a �t� fond� pour emp�cher les aventuriers imprudents d'acc�der au temple, je ne donne pas l'autorisation de passer � n'importe qui."; break;
        case 179 : texte = "Mmmm... Tu as d�j� trouv� 4 cristaux ?*Je dois avouer que tu m'impressionnes...";
            buffer = "Bon c'est entendu, tu as l'autorisation de passer par le cimeti�re, � tes risques et p�rils."; break;
        case 181 : texte = "Va parler au garde au nord du village, il te laissera passer."; break;
        case 182 : texte = "Je vois que tu es toujours vivant...*Etonnant."; break;
        case 183 : texte = "Le temple de l'ombre constitue le point de d�part du chemin menant � un objet de l�gende. Ce village ne sert qu'� dissuader les aventuriers de trop s'en approcher."; break;
        case 184 : texte = "Ainsi tu as trouv� l'Ep�e ?*Mais ne crois pas qu'elle soit � toi pour autant.";
            buffer = "Excalibur fait partie du patrimoine le plus pr�cieux d'Hyrule avec la Triforce, tu devras la ramener dans son sanctuaire une fois ta mission achev�e."; break;
        case 186 : texte = "Les habitants de ce village sont tous des esprits ayant r�pondu � l'appel de la princesse Zelda."; break;
        case 187 : texte = "Lorsque tu as ramen� la paix sur Hyrule et r�unifi� le monde de la lumi�re avec la Terre d'Or, Zelda a secr�tement demand� aux esprits volontaires de cr�er ce village pour bloquer";
            buffer = "l'acc�s � un objet de tr�s grande valeur."; break;
        
        case 189 : texte = "Bienvenue Link!*Laisse-moi t'expliquer ce que je fais ici."; idsuiv=190; break;
        case 190 : texte = "Comme tu l'as certainement remarqu�, des monstres sont apparus partout dans Hyrule. C'est la premi�re fois que je vois des monstres depuis que tu as vaincu Ganon."; idsuiv=191; break;
        case 191 : texte = "Et bien j'ai d�cid� de tous les r�pertorier."; idsuiv=192; break;
        case 192 : texte = "L'ennui c'est que je suis bien trop peureux pour aller � leur rencontre, alors j'ai besoin de ton aide."; idsuiv=193; break;
        case 193 : texte = "Il faut que tu battes chaque type de monstre et que tu viennes me faire ton rapport."; idsuiv=194; break;
        case 194 : texte = "Je te r�compenserai tous les 7 nouveaux types d'ennemis vaincus."; idsuiv=195; break;
        case 195 : texte = "Si tu veux savoir quels ennemis tu as d�j� vaincu, appuye sur L et B."; break;
        
        
        case 196 : 
            if (gpJeu->getJoueur()->getCoeur(43)) {
                if (gpJeu->getJoueur()->nbEnnemis() >= 46) {id=205; chercheText();return;}
                else {id=204; chercheText();return;}
            }
            for (int i = 38; i < 44; i++) 
                if (!gpJeu->getJoueur()->getCoeur(i) 
                && (gpJeu->getJoueur()->nbEnnemis()/7)+37>=i) {
                    id=203; chercheText();return;
                }
            tmp = 7-(gpJeu->getJoueur()->nbEnnemis()%7);
            os << tmp;
            if (tmp>1) texte = "Encore "+os.str()+" ennemis diff�rents avant la prochaine r�compense.";
            else texte = "Plus qu'un nouvel ennemi avant la prochaine r�compense!!!";
            break;
        case 203 : texte = "Accepte ce cadeau pour ta contribution � mon projet :"; break;
        case 204 : texte = "Je suis d�sol� mais je n'ai plus rien � t'offrir..."; break;
        case 205 : texte = "Je n'en crois pas mes yeux, tu as r�ussi � vaincre chaque type d'ennemis !!!*F�licitation Link!!!"; break;
        
        case 206 : texte = "                   Niveau 1 :**               Temple de la for�t"; break;
        case 207 : texte = "                   Niveau 2 :**                 Temple de l'eau"; break;
        case 208 : texte = "                   Niveau 3 :**              Temple de la montagne"; break;
        case 209 : texte = "                   Niveau 4 :**                Temple du d�sert"; break;
        case 210 : texte = "                   Niveau 5 :**                Temple de l'ombre"; break;
        case 211 : texte = "                   Niveau 6 :**                  Temple du feu"; break;
        case 212 : texte = "                   Niveau 7 :**                Temple de la glace"; break;
        case 213 : texte = "                   Niveau ? :**                   Temple secret"; break;
        case 214 : texte = "                 Niveau Final :**                Ch�teau d'Hyrule"; break;
        
        case 215 :texte = "                D�j� fatigu� ?                  ?                CONTINUER                  ?             Sauvegarder et quitter                        Quitter sans sauvegarder           "; break;
        case 216 :texte = "                D�j� fatigu� ?                                   Continuer                     ?          SAUVEGARDER ET QUITTER           ?            Quitter sans sauvegarder           "; break;
        case 217 :texte = "                D�j� fatigu� ?                                   Continuer                                Sauvegarder et quitter              ?         QUITTER SANS SAUVEGARDER          ?"; break;
        
        case 223 : texte = "A l'instant o� Link toucha la Triforce, les monstres disparurent et la paix revint.**La princesse Zelda prit alors une grande d�cision: elle toucha � son tour la Triforce pour exaucer son voeu...**La Triforce fut depuis toujours � l'origine des probl�mes survenus au Royaume, t�t ou tard un autre �tre malfaisant aurait fini par la trouver.**A la seconde o� la princesse toucha la relique, elle disparue � jamais d'Hyrule.";
            buffer = "Depuis ce jour, le peuple d'Hyrule v�cut en paix, sans craindre de nouveaux d�sastres.**Ainsi s'ach�ve la l�gende de Zelda, celle de la  Triforce et de la Terre d'Or.**On dit que l'�p�e Excalibur repose en s�ret� quelque part, et qu'elle constitue le dernier souvenir de la qu�te de Link..."; break;
        case 224 : texte = "F�licitation Link, tu as r�ussi � me trouver. En r�compense, je t'offre le m�daillon de Farore, il augmente ta d�fense d'un point."; break;
        case 225 : texte = "Souhaites-tu sauvegarder ta partie ?**                    ? OUI ?*                      non  "; break;
        case 226 : texte = "Souhaites-tu sauvegarder ta partie ?**                      oui  *                    ? NON ?"; break;
        case 227 : texte = "Partie sauvegard�e."; break;
        
        case 228 : texte = "Le Royaume d'Hyrule �tait en paix depuis que Link, dernier chevalier hylien, avait vaincu le mal�fique Ganon et lui avait repris la pr�cieuse Triforce."; idsuiv = 229; break;
        case 229 : texte = "Nul ne sait quel voeu fit Link en touchant la Triforce, mais il eut comme effet de r�unifier le monde de la lumi�re et celui des t�n�bres, et ramena � la vie les descendants des 7 sages."; idsuiv = 230; break;
        case 230 : texte = "Link remit ensuite � la princesse Zelda la Triforce et l'�p�e Excalibur, et le peuple se mit � croire que la paix durerait.*Mais le peuple se trompait..."; idsuiv=231; break;
        case 231 : texte = "Le souhait de Link � la Triforce eu h�las de f�cheux effets. Ganon et ses sbires furent ainsi ressuscit�s et s'appr�t�rent � attaquer."; idsuiv=232; break;
        case 232 : texte = "Quelque part dans la for�t d'Hyrule, Link dort sans se douter que Ganon est pass� � l'attaque, jusqu'� ce qu'une voix famili�re lui parle dans son sommeil..."; break;
        case 233 : texte = "A l'aide!*A l'aide!*C'est moi! C'est Zelda!*Je te parle par t�l�pathie."; idsuiv = 234; break;
        case 234 : texte = "Je suis retenue prisonni�re dans le donjon du ch�teau! J'ai besoin de ton aide!*Ganon est de retour, et il a certainement d� trouver la Triforce � l'heure qu'il est..."; idsuiv=235; break;
        case 235 : texte = "Viens vite au ch�teau Link, tu es mon seul espoir..."; break;
        case 236 : texte = "AIDE : Appuie sur L et Y pour consulter l'aide."; break;
    }

	break; //French

case 3: // German

    switch (id) {
        case 1  : texte = "Du hast ein Schild gefunden!!!**Deine R�stung steigert sich um einen Punkt!"; break;
        case 2  : texte = "Du hast ein Schwert gefunden!!!**Du kannst jetzt Monster angreifen (dr�ck B)!!!*Halte B um den Spezialhieb aufzuladen!!!"; break;
        case 3  :
            tmp = 4-(gpJeu->getJoueur()->nbQuarts()%4);
            os << tmp;
            texte = "Du hast ein Herzfragment gefunden!!!";
            if (tmp<4) buffer = "Noch "+os.str()+" f�r ein neues Herz n�tig!!!";
            else buffer = "Deine Herzanzahl hat sich gerade erh�ht!!!";
            break;
        case 11 : texte = "N: Link's zu Hause*W: Hyrule-Gebiet*O: Wald-Tempel"; break;
        case 12 : texte = "Berg-Tempel**Nichts f�r Herzkranke, Angsthasen und Schlappschw�nze."; break;
        case 13 : texte = "W: W�ste Gerudo*N: Berg-Tempel"; break;
        case 14 : texte = "N: Berg-Tempel*S: Hyrule Gebiet"; break;
        case 15 : texte = "N: Todesschlucht"; break;
        case 16 : texte = "O: Zum Wald"; break;
        case 17 : texte = "S: See Hylia*O: Spuk-Friedhof"; break;
        case 18 : texte = "S: Zum Dorf Kakariko"; break;
        case 19 : texte = "N: Dorf Kakariko"; break;
        case 20 : texte = "N: Hyrule-Gebiet"; break;
        case 21 : texte = "W: Feuer-Land"; break;
        case 22 : texte = "O: Dorf der Schatten*- Nicht f�r Lebendige -"; break;
        case 23 : texte = "Dunkler Tempel**Bist du ein Geist, der Arbeit sucht? Dann solltest du dich bei uns melden."; break;
        case 24 : texte = "N: Dorf der Schatten*W: See Hylia"; break;
        case 25 : texte = "N: Spuk-Friedhof**Kein Zutritt"; break;
        case 26 : texte = "Dorf der Schatten"; break;
        case 27 : texte = "Ich verkaufe eine Flasche f�r 100 Rupien, abgemacht?*               JA ?          nein  ";
            if ((gpJeu->getJoueur()->hasBouteille(0) && gpJeu->getZone()==8)
            || (gpJeu->getJoueur()->hasBouteille(1) && gpJeu->getZone()==5)
            || (gpJeu->getJoueur()->hasBouteille(2) && gpJeu->getZone()==6)) {id=32; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<100) idsuiv=29;
            else idsuiv=30;
            break;
        case 28 : texte = "Ich verkaufe eine Flasche f�r 100 Rupien, abgemacht?*               ja            NEIN ?"; idsuiv=31; break;
        case 29 : texte = "Bedaure, du hast leider nicht genug Rupien"; break;
        case 30 : texte = "Danke, hier ist die Flasche."; break;
        case 31 : texte = "Komm wieder, falls sich deine Meinung ge�ndert hat."; break;
        case 32 : texte = "Das war leider meine einzige Flasche."; break;
        case 33 : texte = "Du hast eine leere Flasche gekauft!!!**Darin kannst du Getr�nke aufbewahren!!!"; break;
        case 35 : texte = "Die Einwohner dieses Dorfes sprechen einen ungew�hnlichen Dialekt, nix versteh'n..."; break;
        case 36 : texte = "@+@+@+@+@+@+@@@+*@=++=@=+@=+@=+=@*+@+@+@+=+="; break;
        case 37 : texte = "Falls du wirklich hier hindurch willst, musst du erst den Dorf�ltesten fragen!!!"; break;
        case 38 : texte = "Der Dorf�lteste erlaubt dir also zu passieren??? Grrrr... Dann geh doch!!!"; break;
        case 39 : texte = "Geh mir aus dem Weg!!!"; break;
        case 40 : texte = "Normalerweise kommen keine Touristen hier her."; break;
        case 41 : texte = "Einheimische Monster f�rchten sich kaum vor etwas. Zum Gl�ck �berfallen sie nur Menschen."; break;
        case 42 : texte = "Wirklich?*Verstehst du, was ich sage?"; break;
        case 43 : texte = "N: W�ste und Dorf Gerudo"; break;
        case 44 : texte = "S: See Hylia*W: Schloss Hyrule"; break;
        case 45 : texte = "Dorf Kakariko"; break;
        case 46 : texte = "W: Schloss Hyrule"; break;
        case 47 : texte = "Was f�r ein sch�ner Tag!!!"; break;
        case 48 : texte = "Aber warum soll ich auf dieses Viehzeug aufpassen???*Ich hasse H�hner!!!"; break;
        case 49 : texte = "Im Dorfladen kannst du viele n�tzliche Dinge kaufen."; break;
        case 50 : texte = "S: Dorf Kakariko*W: W�ste Gerudo*O: Todesschlucht"; break;
        case 51 : texte = "Dorf Gerudo"; break;
        case 52 : texte = "Verirrt in der W�ste?*Du bist hier:*                        X"; break;
        case 54 : texte = "S: Zum Schloss Hyrule"; break;
        case 55 : texte = "W�sten-Tempel**Tritt ein f�r ein Bad.*(Das Wasser ist nicht zum Trinken da!)"; break;
        case 56 : texte = "Wald-Tempel**Sch�tze die B�ume, fang die Biber!!!"; break;
        case 57 : texte = "See-Tempel**Badekappen vorgeschrieben!"; break;
        case 58 : texte = "Eis-Tempel**Das Personal m�chte dich daran erinnern, dass ein Tempel keine Eissporthalle ist."; break;
        case 59 : texte = "Warst du schon beim Dorfschmied?*Man sagt, er sei sehr begabt, die Ausr�stung f�r Abenteurer aufzuwerten. Er hat viele Kunden."; break;
        case 60 : texte = "Der Tempel ist in der tiefsten W�ste, in einer antiken Oase."; break;
        case 61 : texte = "S: Feuerland*O: Dorf Kakariko"; break;
        case 62 : texte = "Schloss Hyrule"; break;
        case 63 : texte = "O: Dorf Kakariko"; break;
        case 64 : texte = "W: Schildkr�tfelsen*O: See Hylia"; break;
        case 65 : texte = "Geheim-Tempel**Hier ruht das Schwert Excalibur."; break;
        case 66 : texte = "N: Zum Spuk-Friedhof"; break;
        case 67 : texte = "Du hast den Tempelplan gefunden!!!*Dr�ck START, um den Plan anzusehen."; break;
        case 68 : texte = "Du hast den Kompass gefunden!!!*Du kannst nun den Boss und die Truhen auf dem Plan sehen."; break;
        case 69 : texte = "Du hast den Boss-Schl�ssel gefunden!!!"; break;
        case 70 : texte = "Du hast einen Schl�ssel gefunden!!!*Geh auf eine T�r zu, um diese zu �ffnen."; break;
        case 71 : texte = "Du hast die magischen Handschuhe gefunden!!!*Benutz diese (oder dr�ck X) zum Heben/Schieben schwerer Objekte."; break;
        case 72 :
            texte = "Du hast einen Kristall gefunden!!!";
            tmp = 7-gpJeu->getJoueur()->nbCristaux();
            os << tmp;
            if (tmp==6 && !gpJeu->getJoueur()->getAvancement()) buffer = "F�r was mag der wohl gut sein...?";
            else if (tmp>2) buffer = "Es m�ssen noch "+os.str()+" gefunden werden!!!";
            else if (tmp==2) buffer = "Nur noch 2 Exemplare fehlen noch!!!";
            else if (tmp==1) buffer = "Jetzt fehlt nur noch einer!!!";
            else if (tmp==0) buffer = "Du hast jetzt alle 7 Kristalle. Lauf schnell zum Schloss und rette Zelda!!!";
            break;
        case 80 : texte = "Du hast einen Hakenwerfer gefunden!!!*Damit kannst du einige Hindernisse �berwinden."; break;
        case 81 : texte = "Du hast die magische Laterne gefunden!!!*Damit kannst du Feuer entfachen."; break;
        case 82 : texte = "Du hast Schwimmflossen gefunden!!!*Damit kannst du endlich im See baden gehen."; break;
        case 83 : texte = "Du hast einen Hammer gefunden!!!*Damit kannst du Hindernisse zu Brei schlagen."; break;
        case 84 : texte = "Du hast den magischen Feuerstab gefunden!!!*Damit kannst du m�chtige Feuerb�lle schleudern."; break;
        case 85 : texte = "Du hast den magischen Eisstab gefunden!!!*Damit kannst du etwas beliebiges Einfrieren."; break;
        case 86 : texte = "Du hast das Schwert Excalibur gefunden!!!*Selbst Ganon kann nicht seiner Macht standhalten!!! (theoretisch)"; break;
        case 87 : texte = "Endlich Link, du hast mich befreit!!!**Lass uns schnell Ganon finden. Wir m�ssen unbedingt das Triforce zur�ck bekommen!"; break;
        case 89 : texte = "Der Geheimgang hinter dem Thron f�hrt zu Ganon. Beeil dich!"; break;
        case 90 : texte = "Wir sind nahe dran, folge mir!"; break;
        case 91 : texte = "Ich bef�rchte, dass du mit den gegenw�rtigen Waffen Ganon nicht besiegen kannst...*Geh nach Karariko und sprich mit dem Dorf�ltesten. Er findet sicher eine L�sung."; break;
        case 92 : texte = "Ganon ist hinter dieser T�r da.*Ich habe soeben alle deine Wunden geheilt!"; break;
        case 93 : texte = "Ganon ist irgendwo hier im Schloss."; break;
        case 94 : texte = "Du solltest auf Prinzessin Zelda warten!!!"; break;
        case 95 : texte = "W�rdest du nicht dieses mulmige Gef�hl manchmal loswerden wollen???"; break;
        case 96 : texte = "Zelda wartet auf dich!!!"; break;
        case 97 : texte = "Du hast das Triforce gefunden!!!"; break;
        case 98 : texte = "Du hast das Buch Mudora gefunden!!!**Jetzt kannst du endlich die Sprache der antiken Hylian verstehen!!!"; break;
        case 99 : texte = "Du hast mich gefunden, Link. Zur Belohnung schenke ich dir das Din-Amulett. Dies steigert deine R�stung um einen Punkt."; break;
        case 100 : texte = "Du hast mich gefunden, Link. Zur Belohnung schenke ich dir das Nayru-Amulett. Dies steigert deine R�stung um zwei Punkte!!!"; break;
        case 101 : texte = "..."; break;
        case 102 : texte = "Du hast ein magisches Amulett bekommen!!!**Dies steigert deine R�stung!!!"; break;
        case 103 : texte = "Du hast mich gefunden, Link. Zur Belohnung werde ich deine Zauberkraft verdoppeln!!!"; break;
        case 104 : texte = "Deine Zauberkraft hat sich verdoppelt!!!"; break;
        case 105 : texte = "Komm wieder, wenn du eine leere Flasche hast, dann verkauf ich dir einen roten Trank, der alle Wunden heilt."; break;
        case 106 : texte = "Den roten Heiltrank f�r 60 Rupien, abgemacht?*               JA ?          nein  ";
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=105; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<60) idsuiv=29;
            else idsuiv=108; break;
        case 107 : texte = "Den roten Heiltrank f�r 60 Rupien, abgemacht?*               ja            NEIN ?"; break;
        case 108 : texte = "Danke. Hier ist der Trank."; break;
        case 109 : texte = "Du hast einen roten Trank bekommen!!!*(Stellt die volle Gesundheit wieder her)"; break;
        case 110 : texte = "Du hast einen gr�nen Trank bekommen!!!*(Stellt die magischen Kr�fte wieder her)"; break;
        case 111 : texte = "Du hast einen blauen Trank bekommen!!!*(Stellt volle Gesundheit und die magischen Kr�fte wieder her)"; break;
        case 112 : texte = "Hallo, was m�chtest du gerne trinken?"; break;
        case 113 : texte = "-Hick!- Eine Fee fl�sterte mir ins Ohr... -Hick!- ...derjenige, der mich findet, bekommt etwas besonderes... -Hick!!!-"; break;
        case 114 : texte = "Ein Herz f�r 10 Rupien, abgemacht?**               JA ?          nein  ";
            if (gpJeu->getJoueur()->getVie()+gpJeu->getJoueur()->getBoostVie()
            == gpJeu->getJoueur()->getVieMax()) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29;
            else idsuiv=129; break;
        case 115 : texte = "Ein Herz f�r 10 Rupien, abgemacht?**               ja            NEIN ?"; break;
        case 116 : texte = "Kleiner Zaubertrank f�r 20 Rupien, abgemacht?**               JA ?          nein  ";
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<20) idsuiv=29;
            else idsuiv=129; break;
        case 117 : texte = "Kleiner Zaubertrank f�r 20 Rupien, abgemacht?**               ja            NEIN ?"; break;
        case 118 : texte = "Gro�er Zaubertrank f�r 30 Rupien, abgemacht?**               JA ?          nein  ";
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 119 : texte = "Gro�er Zaubertrank f�r 30 Rupien, abgemacht?**               ja            NEIN ?"; break;
        case 120 : texte = "5 Pfeile f�r 30 Rupien, abgemacht?**               JA ?          nein  ";
            if (gpJeu->getJoueur()->getFleche() == gpJeu->getJoueur()->getFlecheMax()
            || !gpJeu->getJoueur()->hasObjet(O_ARC)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 121 : texte = "5 Pfeile f�r 30 Rupien, abgemacht?**               ja            NEIN ?"; break;
        case 122 : texte = "Eine Bombe f�r 30 Rupien, abgemacht?**               JA ?          nein  ";
            if (gpJeu->getJoueur()->getBombe() == gpJeu->getJoueur()->getBombeMax()
            || !gpJeu->getJoueur()->hasObjet(O_SAC_BOMBES)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 123 : texte = "Eine Bombe f�r 30 Rupien, abgemacht?**               ja            NEIN ?"; break;
        case 124 : texte = "Ein Bogen f�r 1000 Rupien, abgemacht?**               JA ?          nein  ";
            idsuiv=29; break;
        case 125 : texte = "Ein Bogen f�r 1000 Rupien, abgemacht?**               ja            NEIN ?"; break;
        case 126 : texte = "Ein Bogen f�r 50 Rupien, abgemacht?**               JA ?          nein  ";
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<50) idsuiv=29;
            else idsuiv=129; break;
        case 127 : texte = "Ein Bogen f�r 50 Rupien, abgemacht?**               ja            NEIN ?"; break;
        case 128 : texte = "Das brauchst du jetzt nicht."; break;
        case 129 : texte = "Danke."; break;
        case 130 : texte = "Du hast den Bogen bekommen!!!*Damit kannst du auf entfernte Ziele schie�en."; break;
        case 131 : texte = "W�hle, was du begehrst."; break;
        case 132 : texte = "Was???*Du hast einen Auftrag vom Dorf�ltesten???*Nun gut, dann gebe ich dir einen Preisnachlass auf den Bogen."; break;
        case 133 : texte = "Hallo Link. Ich bin der Dorf�lteste. Ich dachte mir schon, dass du zu mir kommen wirst."; idsuiv=134; break;
        case 134 : texte = "Seit heute fr�h treiben sich Monster in Hyrule herum. Ich versuchte dar�ber mit Zelda zu sprechen, aber wie du bereits sagtest, blockiert ein Zauberbann den Eingang zum Schloss..."; idsuiv=136; break;
        case 136 : texte = "Du sagst, Ganon sei Schuld f�r all dies? Er soll das Triforce gestohlen und Prinzessin Zelda gefangen halten?"; idsuiv=137; break;
        case 137 : texte = "Mmmm... Die Situation ist ernster, als ich dachte..."; idsuiv=138; break;
        case 138 : texte = "Wir m�ssen rasch handeln. Du musst erneut gegen Ganon k�mpfen!"; idsuiv=139; break;
        case 139 : texte = "Wie kommt man ins Schloss? Ich h�tte da eine Idee..."; idsuiv=140; break;
        case 140 : texte = "Wie bekannt, wurden die Kr�fte der 7 Weisen von Zauberer Aghanim in 7 Kristalle gesperrt, als er versuchte den Pfad zur Dunklen Welt zu �ffnen, wo Ganon sich aufh�lt."; idsuiv=141; break;
        case 141 : texte = "Jetzt, nachdem du Ganon besiegt, das Triforce gefunden und damit die 7 Weisen wiederbelebt hast, haben diese Kristalle ihre magischen Kr�fte immer noch erhalten."; idsuiv=142; break;
        case 142 : texte = "Sie sind tief im Inneren der 7 Tempel versteckt worden. Hol sie dir alle, dann kannst du Ganon's Zauberbann am Schlosseingang l�sen."; idsuiv=143; break;
        case 143 : texte = "Das wird jedoch nicht einfach werden, denn Ganon hat sicher seine besten Einheiten zum Schutz dieser Kristalle eingesetzt..."; idsuiv=144; break;
        case 144 : texte = "Zu guter Letzt: Du wirst mit deiner jetzigen Ausr�stung nicht weit kommen. Geh zum Waffenh�ndler und sage ihm, dass du in meinem Auftrag kommst. Er wird sich dann wohl erkenntlich zeigen."; break;
        case 145 : texte = "Geh zum Waffenh�ndler und sage ihm, dass du in meinem Auftrag kommst! Er wird sich dann wohl erkenntlich zeigen."; break;
        case 146 : texte = "Du brauchst alle 7 Kristalle, um Zelda und Hyrule retten zu k�nnen."; break;
        case 147 : texte = "Du besitzt alle 7 Kristalle? Geh nun geradewegs zum Schloss und befrei' erst die Prinzessin. Sie wird besser als ich wissen, wie Hyrule gerettet werden kann."; break;
        case 148 : texte = "Sind deine Waffen gegen Ganon null und nichtig? Deswegen musst du das Schwert Excalibur finden. Man sagt, es sei gut versteckt in einem Geheim-Tempel."
            "*Nebenbei: Der Weg zum Schwert Excalibur f�hrt mitten durch ein Dorf, nur von Monstern bewohnt... Ich frag mich, ob es so ein Dorf gibt..."; break;
        case 150 : texte = "Nun, ich bef�rchte dass deine Ausr�stung unzul�nglich ist, um diesen Tempel zu erreichen. Du solltest zum Schmied von Gerudo gehen..."; break;
        case 151 : texte = "Es ist jetzt an der Zeit, Ganon ins Auge zu blicken und ihm das Triforce abzunehmen!"; break;
        case 152 : texte = "Heh! Du musst erst bezahlen, wenn du eine meiner Truhen �ffnen willst!!!"; break;
        case 153 : texte = "Eine dieser Truhen enth�lt ein Herzfragment. Willst du f�r 10 Rupien dein Gl�ck versuchen? Du darfst nur eine Truhe �ffnen, abgemacht?*                JA ?          nein";
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29; break;
        case 154 : texte = "Eine dieser Truhen enth�lt ein Herzfragment. Willst du f�r 10 Rupien dein Gl�ck versuchen? Du darfst nur eine Truhe �ffnen, abgemacht?*                ja            NEIN ?"; break;
        case 155 : texte = "W�hle eine Truhe."; break;
        case 156 : texte = "Ich habe leider keine Preise mehr f�r dieses Spiel, bedaure."; break;
        case 157 : texte = "Du hast verloren! Diese Truhe war leer. Versuch es noch einmal!"; break;
        case 158 : texte = "Hallo! Falls du den Schmied suchst, er wohnt etwas abseits."; break;
        case 159 : texte = "Hallo Link, ich bin der Dorf�lteste hier.*Du solltest zum Schmied gehen und ihm zeigen, was du brauchst, damit er deine Ausr�stung verbessern kann.";
            buffer = "Ich kannte dein Anliegen schon, deshalb habe ich bereits mit ihm gesprochen.*Alles wird f�r dich kostenlos erledigt."; break;
        case 160 : texte = "Du brauchst diesen Trank jetzt nicht zu benutzen."; break;
        case 161 : texte = "Gr�ner Zaubertrank f�r 40 Rupien, einverstanden?*               JA ?          nein  ";
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=163; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<40) idsuiv=29;
            else idsuiv=108; break;
        case 162 : texte = "Gr�ner Zaubertrank f�r 40 Rupien, einverstanden?*               ja            NEIN ?"; break;
        case 163 : texte = "Komm wieder, wenn du eine leere Flasche hast, dann verkauf ich dir einen gr�nen Trank, welcher die Zauberkraft wiederherstellt."; break;
        case 164 : texte = "Komm sp�ter wieder, ich bin zu sehr besch�ftigt!"; break;
        case 165 : texte = "Kann ich etwas f�r dich tun?";
            if (gpJeu->getJoueur()->getEpee()==1) {id=166; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_GANTS)==1 && gpJeu->getJoueur()->getObjet()==8) {
                id=169; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_ARC)==2 && gpJeu->getJoueur()->getObjet()==0
            && gpJeu->getJoueur()->nbCristaux()==7) {
                id=172; chercheText();break;}
            break;
        case 166 : texte = "Soll ich dein Schwert h�rten?**               JA ?          nein  "; break;
        case 167 : texte = "Soll ich dein Schwert h�rten?**               ja            NEIN ?"; break;
        case 168 : texte = "Dein Schwert hat seine Kraft verdreifacht. Au�erdem kann es jetzt magische Hiebe schleudern, da guckst du!!!*"; break;
        case 169 : texte = "Soll ich deine Handschuhe aufwerten?**               JA ?          nein  "; break;
        case 170 : texte = "Soll ich deine Handschuhe aufwerten?**               ja            NEIN ?"; break;
        case 171 : texte = "Die Kraft deiner Handschuhe erm�glicht dir nun, schwere Brocken zu heben."; break;
        case 172 : texte = "Soll ich deinen Bogen aufwerten?**               JA ?          nein  "; break;
        case 173 : texte = "Soll ich deinen Bogen aufwerten?**               ja            NEIN ?"; break;
        case 174 : texte = "Dein Bogen verwendet nun Silberpfeile mit kataklystischer Energie!!!"; break;
        case 175 : texte = "Komm wieder, wenn du eine leere Flasche hast, dann verkauf ich dir den blauen Trank, der Gesundheit und Zauberkraft wiederherstellt."; break;
        case 176 : texte = "Der blaue Zaubertrank f�r 160 Rupien, einverstanden?*               JA ?          nein  ";
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=175; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<160) idsuiv=29;
            else idsuiv=108; break;
        case 177 : texte = "Der blaue Zaubertrank f�r 160 Rupien, einverstanden?*               ja            NEIN ?"; break;
        case 178 : texte = "Unser Dorf�ltester hat festgelegt, unvorsichtige Abenteurer vom Tempel fernzuhalten. Ich erlaube niemandem zu passieren."; break;
        case 179 : texte = "Mmmm... Du hast bereits 4 Kristalle gefunden?*Ich muss zugeben, dass du mich beeindruckst...";
            buffer = "Nun gut, du darfst das Gr�berfeld �berqueren, aber auf eigenes Risiko."; break;
        case 181 : texte = "Sag dem W�chter im Norden des Dorfes, dass er dich durchlassen soll."; break;
        case 182 : texte = "Ach soo, du lebst immer noch...*Erstaunlich."; break;
        case 183 : texte = "Der Dunkle Tempel ist der Startpunkt des Weges zum Erreichen eines legend�ren Objektes. Dieses Dorf existiert nur deshalb, um Abenteurer davon fern zu halten."; break;
        case 184 : texte = "Du hast also das Schwert Excalibur gefunden?*Aber glaub' nicht, dass du es f�r immer behalten kannst.";
            buffer = "Das Schwert Excalibur ist eines der wertvollsten Kulturg�ter von Hyrule, zusammen mit dem Triforce. Du wirst es am Ende deiner Mission in den Altarraum zur�ck legen!"; break;
        case 186 : texte = "Alle Bewohner dieses Dorfes sind Geister, die Prinzessin Zelda's Anweisungen treu befolgen."; break;
        case 187 : texte = "Als der Frieden in Hyrule wieder einzog und die Lichtwelt mit dem Goldenen Land wieder vereinigt war, bat Zelda (heimlich) einige Geister diese Stadt zu errichten,";
            buffer = "um den Zugang zu einem sehr wertvollen Objekt zu blockieren."; break;
        case 189 : texte = "Willkommen Link!*Lass mich dir erkl�ren, was ich hier mache."; idsuiv=190; break;
        case 190 : texte = "Wie du sicher bemerkt hast, sind Monster in Hyrule aufgetaucht. Es ist das erste mal, seit deinem Sieg �ber Ganon, dass ich Monster beobachte."; idsuiv=191; break;
        case 191 : texte = "Nun habe ich beschlossen, alle Monster zu katalogisieren."; idsuiv=192; break;
        case 192 : texte = "Ungl�cklicherweise bin ich wirklich zu �ngstlich, diesen pers�nlich zu begegnen. Deshalb brauche ich deine Hilfe."; idsuiv=193; break;
        case 193 : texte = "Du musst jede unbekannte Monster-Art besiegen und mir im Anschluss davon berichten."; idsuiv=194; break;
        case 194 : texte = "Jedes mal, wenn du 7 neue Arten von Monstern besiegt hast, gebe ich dir ein Herzfragment daf�r."; idsuiv=195; break;
        case 195 : texte = "Willst du wissen, welche Monster du bereits besiegt hast, dann dr�ck L und B."; break;
        case 196 :
            if (gpJeu->getJoueur()->getCoeur(43)) {
                if (gpJeu->getJoueur()->nbEnnemis() >= 46) {id=205; chercheText();return;}
                else {id=204; chercheText();return;}
            }
            for (int i = 38; i < 44; i++)
                if (!gpJeu->getJoueur()->getCoeur(i)
                && (gpJeu->getJoueur()->nbEnnemis()/7)+37>=i) {
                    id=203; chercheText();return;
                }
            tmp = 7-(gpJeu->getJoueur()->nbEnnemis()%7);
            os << tmp;
            if (tmp>1) texte = "Abermals "+os.str()+" unbekannte Monster bis zur n�chsten Belohnung.";
            else texte = "Du ben�tigst nur noch ein unbekanntes Monster bis zur n�chsten Belohnung!!!";
            break;
        case 203 : texte = "Nimm dieses Geschenk f�r deine tatkr�ftige Unterst�tzung meines Projekts:"; break;
        case 204 : texte = "Tut mir leid, aber ich habe keine Geschenke mehr f�r dich..."; break;
        case 205 : texte = "Ich kann es nicht fassen. Dir gelang es, alle Monster-Arten zu besiegen!!!*Gratulation, Link!!!"; break;
        case 206 : texte = "                    Level 1:**                  Wald-Tempel"; break;
        case 207 : texte = "                    Level 2:**                 Wasser-Tempel"; break;
        case 208 : texte = "                    Level 3:**                  Berg-Tempel"; break;
        case 209 : texte = "                    Level 4:**                 W�sten-Tempel"; break;
        case 210 : texte = "                    Level 5:**                 Dunkler Tempel"; break;
        case 211 : texte = "                    Level 6:**                  Feuer-Tempel"; break;
        case 212 : texte = "                    Level 7:**                   Eis-Tempel"; break;
        case 213 : texte = "                    Level ?:**                 Geheim-Tempel"; break;
        case 214 : texte = "                 Letzter Level:**                 Schloss Hyrule"; break;

        case 215 :texte = "                  Schon m�de?                   ?               WEITER MACHEN               ?               Sichern und beenden                          Beenden ohne zu sichern           "; break;
        case 216 :texte = "                  Schon m�de?                                   weiter machen                  ?            SICHERN UND BEENDEN            ?             Beenden ohne zu sichern           "; break;
        case 217 :texte = "                  Schon m�de?                                   weiter machen                               Sichern und beenden               ?          BEENDEN OHNE ZU SICHERN          ?"; break;

        case 223 : texte = "Als Link das Triforce ber�hrte, verschwanden auch alle Monster und Frieden zog ein.**"
          "Dann fasste Prinzessin Zelda einen mutigen Entschluss: Sie ber�hrte kreisend das Triforce und w�nschte sich etwas.**"
          "Das Triforce hat schon genug Probleme im K�nigreich verursacht. Fr�her oder sp�ter wird erneut ein B�sewicht das Triforce finden.**"
          "Im gleichen Moment, als die Prinzessin die Reliquie ber�hrte, verschwand diese f�r immer von Hyrule.";
          buffer = "Seit diesem Tag lebten die Bewohner von Hyrule in Frieden, ohne Angst vor neuem Unheil.**"
          "Deshalb ist die Geschichte von Zelda, dem Triforce und dem Goldenen Land Hyrule hiermit beendet.**"
          "Das Schwert Excalibur gilt als sicher verwahrt (-irgendwo an einem geheimen Ort-) und ist Link's j�ngstes Beutest�ck..."; break;
        case 224 : texte = "Du hast mich gefunden, Link. Zur Belohnung schenke ich dir das Farore-Amulett. Dies steigert deine R�stung um einen Punkt..."; break;
        case 225 : texte = "M�chtest du dein Spiel sichern?**                    ?  JA  ?*                      nein  "; break;
        case 226 : texte = "M�chtest du dein Spiel sichern?**                       ja   *                    ? NEIN ?"; break;
        case 227 : texte = "Spielstand gesichert."; break;
        case 228 : texte = "Das K�nigreich Hyrule lebte in Frieden, seit Link, der letzte Ritter von Hyrule, den heimt�ckischen Ganon besiegte und das wertvolle Triforce von ihm zur�ckgewann."; idsuiv = 229; break;
        case 229 : texte = "Niemand kennt die Worte von Link's Wunsch an das Triforce, allerdings hat dieser die Wiedervereinigung der Hellen mit der Dunklen Welt bewirkt, sowie *die Auferstehung der 7 Weisen."; idsuiv = 230; break;
        case 230 : texte = "Schlie�lich �bergab Link das Triforce und das Schwert Excalibur an Prinzessin Zelda, und die Leute begannen zu glauben, dass nun f�r immer Frieden herrschen wird.                        Aber die Leute lagen falsch..."; idsuiv=231; break;
        case 231 : texte = "... denn ungl�cklicherweise hatte Link's Wunsch auch negative Auswirkungen. Ganon und seine Schergen sind wiederauferstanden und machen sich kampfbereit."; idsuiv=232; break;
        case 232 : texte = "Irgendwo im Wald von Hyrule schl�ft Link und ahnt noch nicht, dass Ganon bereits den Kampf begonnen hat,";
            buffer="bis eine wohlbekannte Stimme zu ihm spricht, w�hrend er weiter fest schl�ft..."; break;
        case 233 : texte = "Hilf mir!*Hilf mir!*Ich bin's, Zelda!*Ich spreche zu dir �ber Telepathie."; idsuiv = 234; break;
        case 234 : texte = "Ich bin Gefangene im Kerker des Schlosses!*Ich brauche deine Hilfe!*Ganon ist zur�ckgekehrt, und er hat bestimmt schon das Triforce gefunden..."; idsuiv=235; break;
        case 235 : texte = "Komm schnell zu mir ins Schloss, Link, du bist meine einzige Hoffnung..."; break;
        case 236 : texte = "Brauchst du HILFE, dann dr�ck L und X."; break;
    }

break; // German

case 4: // Italian

    switch (id) {
        case 1  : texte = "Hai trovato uno scudo!**La tua difesa aumenta di un punto!"; break;
        case 2  : texte = "Hai trovato una spada!**Ora puoi combattere i monstri con B .*Lascia premuto B per caricare un attacco rotante!"; break;
        case 3  : 
            tmp = 4-(gpJeu->getJoueur()->nbQuarts()%4);
            os << tmp;
            texte = "Hai trovato una parte di cuore!!!";
            if (tmp<4) buffer = "te ne servono "+os.str()+" ancora per un nuvo cuore.";
            else buffer = "Il tuo numero di cuori � aumentato!";
            break;
        case 11 : texte = "N: Casa di Link*O: Terra di Hyrule*E: Tempio della foresta"; break;
        case 12 : texte = "Tempio della montagna**Non per cardiopatici, paurosi o deboli di cuore."; break;
        case 13 : texte = "O: Entrata del Deserto*N: Tempio della montagna"; break;
        case 14 : texte = "N: Tempio della montagna*S: Terra di Hyrule"; break;
        case 15 : texte = "N: Montagna della morte"; break;
        case 16 : texte = "E: Entrata della foresta"; break;
        case 17 : texte = "S: Lago Hylia*E: Cimitero infestato"; break;
        case 18 : texte = "S: Al villaggio Kakariko"; break;
        case 19 : texte = "N: Villaggio Kakariko"; break;
        case 20 : texte = "N: Terra di Hyrule"; break;
        case 21 : texte = "O: Terra di Fuoco"; break;
        case 22 : texte = "E: Villaggio Ombra*- Non per i vivi -"; break;
        case 23 : texte = "Tempio Oscuro**Se sei un fantasma e cerchi un lavoro, vieni a trovarci."; break;
        case 24 : texte = "N: Villaggio Ombra*O: Lago Hylia"; break;
        case 25 : texte = "N: Cimitero infestato**Non entrare"; break;
        case 26 : texte = "Villaggio Ombra"; break;
        case 27 : texte = "Vendo una bottiglia per 100 rupie, sei interessato?*              SI' ?            no  "; 
            if ((gpJeu->getJoueur()->hasBouteille(0) && gpJeu->getZone()==8)
            || (gpJeu->getJoueur()->hasBouteille(1) && gpJeu->getZone()==5)
            || (gpJeu->getJoueur()->hasBouteille(2) && gpJeu->getZone()==6)) {id=32; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<100) idsuiv=29;
            else idsuiv=30;
            break;
        case 28 : texte = "Vendo una bottiglia per 100 rupie, sei interessato?*              s�               NO ?"; idsuiv=31; break;
        case 29 : texte = "Spiacente, non hai abbastanza rupie"; break;
        case 30 : texte = "Grazie, ecco la tua bottiglia."; break;
        case 31 : texte = "Torna ancora se cambi idea."; break;
        case 32 : texte = "Spiacente, era la mia unica bottiglia."; break;
        case 33 : texte = "Hai trovato una bottiglia vuota!**Ti aiuter� a conservare le pozioni."; break;
        case 35 : texte = "Gli abitanti del villaggio hanno uno strano dialetto. Non capisco nulla..."; break;
        case 36 : texte = "@+@+@+@+@+@+@@@+*@=++=@=+@=+@=+=@*+@+@+@+=+="; break;
        case 37 : texte = "Chiedi il permesso al capo se vuoi passare!"; break;
        case 38 : texte = "Il capo ti ha concesso di passare? Grrrr... Allora vai!"; break;
        case 39 : texte = "Sparisci dalla mia vista!"; break;
        case 40 : texte = "Non abbiamo spesso visitatori da queste parti."; break;
        case 41 : texte = "I mostri locali temono poche cose. Fortunatamente attaccano solo gli umani."; break;
        case 42 : texte = "Davvero?*Capisci quello che sto dicendo?"; break;
        case 43 : texte = "N: Deserto e Villaggio Gerudo"; break;
        case 44 : texte = "S: Lago Hylia*O: Castello di Hyrule"; break;
        case 45 : texte = "Villaggio Kakariko"; break;
        case 46 : texte = "O: Castello di Hyrule"; break;
        case 47 : texte = "Che bella giornata!"; break;
        case 48 : texte = "Perch� ho accettato di prendermi cura di quelle bestie?*Io odio le galline!"; break;
        case 49 : texte = "Puoi trovare molte cose nel negozio del villaggio."; break;
        case 50 : texte = "S: Villaggio Kakariko*O: Deserto*E: Montagna della Morte"; break;
        case 51 : texte = "Villagio Gerudo"; break;
        case 52 : texte = "Ti sei perso nel deserto?*Tu sei qui:*                        X"; break;
        case 54 : texte = "S: Al Castello di Hyrule"; break;
        case 55 : texte = "Tempio del deserto**Vieni a provare le nostre terme.*(L'acqua non  � potabile)"; break;
        case 56 : texte = "Tempio della foresta**Salva gli alberi, mangia un castoro!"; break;
        case 57 : texte = "Tempio del Lago**Cuffia da bagno obbligatoria"; break;
        case 58 : texte = "Tempio di Ghiaccio**Il personale vi ricorda che un tempio non � una pista di pattinagio."; break;
        case 59 : texte = "Hai visto il fabbro del villaggio?*Si dice che sia molto abile nel migliorare l'equipaggiamento degli avventurieri. Molte persone gli fanno visita."; break;
        case 60 : texte = "Il tempio � in pieno deserto, in una antica oasi."; break;
        case 61 : texte = "S: Terra del fuoco*E: Villaggio Kakarico"; break;
        case 62 : texte = "Castello di Hyrule"; break;
        case 63 : texte = "E: Villaggio Kakariko"; break;
        case 64 : texte = "O: Roccia della tartaruga*E: Lago Hylia"; break;
        case 65 : texte = "Tempio segreto**Qui riposa la spada purificatrice, La Spada Suprema.."; break;
        case 66 : texte = "N: Al cimitero infestato"; break;
        case 67 : texte = "Hai trovato la mappa del tempio!*Premi START per vedere la mappa."; break;
        case 68 : texte = "Hai trovato la bussola!*Puoi localizzare i bauli e il Boss sulla mappa."; break;
        case 69 : texte = "Hai trovato la chiave per il Boss!"; break;
        case 70 : texte = "Hai trovato una piccola chiave!*Avvicinati ad una porta per aprirla."; break;
        case 71 : texte = "Hai trovato i guanti!*Usali per alzare gli oggetti con il tasto X."; break;
        case 72 : 
            texte = "Hai trovato un Cristallo Magico!"; 
            tmp = 7-gpJeu->getJoueur()->nbCristaux();
            os << tmp;
            if (tmp==6 && !gpJeu->getJoueur()->getAvancement()) buffer = "A cosa potr� servire...?";
            else if (tmp>2) buffer = "Ce ne sono "+os.str()+" ancora da trovare!";
            else if (tmp==2) buffer = "Ne rimangono solo due da trovare!";
            else if (tmp==1) buffer = "Te ne manca uno solo!";
            else if (tmp==0) buffer = "Hai tutti i cristalli, corri al castello e salva Zelda!";
            break;
        case 80 : texte = "Hai trovato un rampino!*Usalo per superare gli ostacoli."; break;
        case 81 : texte = "Hai trovato una lanterna!*Usala per dare fuoco."; break;
        case 82 : texte = "Hai trovato delle pinne!*Selezionale dal menu per nuotare nell'acqua."; break;
        case 83 : texte = "Hai trovato un Martello Magico*Usalo per schiacciare gli ostacoli."; break;
        case 84 : texte = "Hai trovato la Bacchetta di Fuoco!*Da ora puoi lanciare potenti fiammate."; break;
        case 85 : texte = "Hai trovato la bacchetta di ghiaccio!*Usala per congelare ogni cosa a distanza."; break;
        case 86 : texte = "Hai trovato la Spada Suprema!*Neanche Ganon pu� resistere al suo potere... in teoria!"; break;
        case 87 : texte = "Grazie per avermi salvato, Link.***Cerchiamo in fretta Ganon; dobbiamo riprenderci la Triforza!"; break;
        case 89 : texte = "Il passaggio segreto dietro il trono conduce a Ganon. Affrettati!"; break;
        case 90 : texte = "Siamo molto vicini, seguimi!"; break;
        case 91 : texte = "Temo tu non sia in grado di sconfiggere Ganon con le tue attuali armi...*Vai a parlare con il Capo del villaggio Kakariko, sono sicura che trover� una soluzione."; break;
        case 92 : texte = "Ganon � proprio oltre quella porta. Ora curo le tue ferite."; break;
        case 93 : texte = "Ganon � ancora da qualche parte nel castello."; break;
        case 94 : texte = "Dovresti aspettare la Principessa Zelda!"; break;
        case 95 : texte = "Non hai la sensazione di star dimenticando qualcosa?"; break;
        case 96 : texte = "Zelda ti sta aspettando!"; break;
        case 97 : texte = "Hai trovato la Triforza!"; break;
        case 98 : texte = "Hai trovato il libro di Mudora!**Ora puoi capire l'antico linguaggio di Hylian!"; break;
        case 99 : texte = "Congratulazioni per avermi trovato, Link. Come ricompensa ti dono il Pendente di Din. Aumenta la tua difesa di un punto."; break;
        case 100 : texte = "Congratulazioni per avermi trovato, Link. Come ricompensa ti dono il Pendente di Nayru. Aumenta la tua difesa di due punti."; break;
        case 101 : texte = "..."; break;
        case 102 : texte = "Hai ottenuto un pendente magico!**La tua difesa aumenta!"; break;
        case 103 : texte = "Congratulazioni per avermi trovato, Link. Come ricompensa raddoppier� la capacit� della tua carica di magia!"; break;
        case 104 : texte = "La tua capacit� di carica magica � raddoppiata!"; break;
        case 105 : texte = "Torna quando avrai un  bottiglia e ti vender� una pozione rossa che ripristina la tua salute."; break;
        case 106 : texte = "Una pozione rossa per 60 rupie. Sei interessato?*              SI' ?            no  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=105; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<60) idsuiv=29;
            else idsuiv=108; break;
        case 107 : texte = "Una pozione rossa per 60 rupie. Sei interessato?*              s�               NO ?"; break;
        case 108 : texte = "Grazie, ecco la tua pozione.";break;
        case 109 : texte = "Hai ottenuto una pozione rossa!*Bevila per ripristinare la tua salute."; break;
        case 110 : texte = "Hai ottenuto una pozione verde!*Bevila per ripristinare la tua carica magica."; break;
        case 111 : texte = "Hai ottenuto una pozione blu!*Bevila per ripristinare salute e carica magica."; break;
        case 112 : texte = "Salve, cosa hai voglia di bere?"; break;
        case 113 : texte = "-Hiccup!- Si dice che una fata regali oggetti incantati... -Hiccup!- ...agli avventurieri che la trovano... -Hiccup!!!-"; break;
        case 114 : texte = "Un cuore per 10 rupie. Sei interessato?**              SI' ?            no  "; 
            if (gpJeu->getJoueur()->getVie()+gpJeu->getJoueur()->getBoostVie()
            == gpJeu->getJoueur()->getVieMax()) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29;
            else idsuiv=129; break;
        case 115 : texte = "Un cuore per 10 rupie. Sei interessato?**              s�               NO ?"; break;
        case 116 : texte = "Un po' di magia per 20 rupie. Sei interessato?**              SI' ?            no  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<20) idsuiv=29;
            else idsuiv=129; break;
        case 117 : texte = "Un po' di magia per 20 rupie. Sei interessato?**              s�               NO ?"; break;
        case 118 : texte = "Un po' di magia per 30 rupie. Sei interessato?**              SI' ?            no  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 119 : texte = "Un po' di magia per 30 rupie. Sei interessato?**              s�               NO ?"; break;
        case 120 : texte = "5 frecce per 30 rupie. Sei interessato?**              SI' ?            no  "; 
            if (gpJeu->getJoueur()->getFleche() == gpJeu->getJoueur()->getFlecheMax() 
            || !gpJeu->getJoueur()->hasObjet(O_ARC)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 121 : texte = "5 frecce per 30 rupie. Sei interessato?**              s�               NO ?"; break;
        case 122 : texte = "Una bomba per 30 rupie. Sei interessato?**              SI' ?            no  "; 
            if (gpJeu->getJoueur()->getBombe() == gpJeu->getJoueur()->getBombeMax() 
            || !gpJeu->getJoueur()->hasObjet(O_SAC_BOMBES)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 123 : texte = "Una bomba per 30 rupie. Sei interessato?**              s�               NO ?"; break;
        case 124 : texte = "Un arco per 1000 rupie. Sei interessato?**              SI' ?            no  "; 
            idsuiv=29; break;
        case 125 : texte = "Un arco per 1000 rupie. Sei interessato?**              s�               NO ?"; break;
        case 126 : texte = "Un arco per 50 rupie. Sei interessato?**              SI' ?            no  "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<50) idsuiv=29;
            else idsuiv=129; break;
        case 127 : texte = "Un arco per 50 rupie. Sei interessato?**              s�               NO ?"; break;
        case 128 : texte = "Non ne hai bisogno ora."; break;
        case 129 : texte = "Grazie."; break;
        case 130 : texte = "Hai ottenuto un arco!*Usalo per colpire bersagli lontani."; break;
        case 131 : texte = "Prendi ci� che vuoi."; break;
        case 132 : texte = "Cosa?*Sei in missione per il capo?*Bene, allora ti far� uno sconto sull'arco"; break;
        case 133 : texte = "Salve Link, Sono il capo del villaggio. Sospettavo che stessi arrivando."; idsuiv=134; break;
        case 134 : texte = "Da stamane i mostri si aggirano per Hyrule. Ho provato a parlarne a Zelda, ma come forse gi� sai, una potente magia blocca l'accesso al castello."; idsuiv=136; break;
        case 136 : texte = "Dici che Ganon � responsabile di tutto questo? Ha rubato la Triforza e tiene prigioniera Zelda?"; idsuiv=137; break;
        case 137 : texte = "Mmmm... La situazione � pi� seria di quanto pensassi..."; idsuiv=138; break;
        case 138 : texte = "Dobbiamo agire velocemente. Devi affrontare Ganon di nuovo!"; idsuiv=139; break;
        case 139 : texte = "Come entrare al castello? Penso di avere un'idea..."; idsuiv=140; break;
        case 140 : texte = "Come sai il potere dei 7 saggi � stato racchiuso in 7 cristalli da Aghanim quando stava provando ad aprire la via per il Mondo Oscuro dove si trovava Ganon."; idsuiv=141; break;
        case 141 : texte = "Anche se hai fatto risorgere dalla morte i discendenti dei 7 saggi quando hai sconfitto Ganon e trovato la Triforza, quei cristalli hanno mantenuto il loro potere."; idsuiv=142; break;
        case 142 : texte = "Sono stati ben nascosti nei 7 templi. Radunali tutti e sarai in grado di superare la magia di Ganon."; idsuiv=143; break;
        case 143 : texte = "Per� non sar� facile. Ganon avr� sicuramente inviato le sue migliori truppe a proteggere quei cristalli."; idsuiv=144; break;
        case 144 : texte = "Un'ultima cosa. Non andrai lontano con il tuo attuale equipaggiamento. Vai ad incontrare l'armaiolo e digli che vieni per conto mio. vedrai che ti tratter� bene."; break;
        case 145 : texte = "Vai ad incontrare l'armaiolo e digli che vieni per conto mio. vedrai che ti tratter� bene."; break;
        case 146 : texte = "Devi radunare i 7 cristalli per avere una possibilit� di salvare Zelda e Hyrule."; break;
        case 147 : texte = "Hai trovato i 7 cristalli? Vai al Castello! Per prima cosa salva la principessa. Lei sapr� meglio di me come salvare Hyrule."; break;
        case 148 : texte = "Le tue armi sono inutili contro Ganon? Devi trovare la Spada Suprema. Si dice sia nascosta in un Tempio Segreto.*La strada che porta alla Spada Purificatrice si dice attraversi un villaggio popolato da mostri...*Mi chiedo se un tale villaggio esista."; break;
        case 150 : texte = "Comunque, temo che il tuo equipaggiamento sia inadeguato per raggiungere quel tempio. Dovresti recarti dal fabbro del Villaggio Gerudo."; break;
        case 151 : texte = "E' tempo di affrontare Ganon e riprendersi la Triforza!"; break;
        case 152 : texte = "Hei! Devi pagare per aprire uno dei miei bauli!"; break;
        case 153 : texte = "Uno di questi bauli contiene una parte di cuore. Vuoi provare per 10 rupie?*Puoi aprire un solo baule a tentativo, ok?               SI' ?            no  "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29; break;
        case 154 : texte = "Uno di questi bauli contiene una parte di cuore. Vuoi provare per 10 rupie?*Puoi aprire un solo baule a tentativo, ok?               s�               NO ?"; break;
        case 155 : texte = "Scegli un baule."; break;
        case 156 : texte = "Non ho pi� premi da mettere in palio, mi dispiace."; break;
        case 157 : texte = "Hai perso! Questo baule � vuoto. Prova ancora!"; break;
        case 158 : texte = "Salve! Se cerchi il fabbro, vive un po' pi� avanti."; break;
        case 159 : texte = "Salve Link, io sono il capo del villaggio.*Dovresti andare ad incontrare il fabbro e mostrargli quale equipaggiamento vuoi che migliori.";
            buffer = "Sono a conoscenza della tua missione, quindi lo ho gi� avvisato.*Sar� tutto gratis per te."; break;
        case 160 : texte = "Non hai bisogno di bere questa pozione ora."; break;
        case 161 : texte = "Una pozione verde per 40 rupie. Sei interessato?*              SI' ?            no  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=163; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<40) idsuiv=29;
            else idsuiv=108; break;
        case 162 : texte = "Una pozione verde per 40 rupie. Sei interessato?*              s�               NO ?"; break;
        case 163 : texte = "Torna quando avrai una bottiglia vuota e ti vender� una pozione verde che ripristina il tuo livello di magia."; break;
        case 164 : texte = "Torna pi� tardi. Ho troppi lavori da finire!"; break;
        case 165 : texte = "Posso fare qualcosa per te?";
            if (gpJeu->getJoueur()->getEpee()==1) {id=166; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_GANTS)==1 && gpJeu->getJoueur()->getObjet()==8) {
                id=169; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_ARC)==2 && gpJeu->getJoueur()->getObjet()==0 
            && gpJeu->getJoueur()->nbCristaux()==7) {
                id=172; chercheText();break;}
            break;
        case 166 : texte = "Vuoi che tempri la tua spada?**              SI' ?            no  "; break;
        case 167 : texte = "Vuoi che tempri la tua spada?**              s�               NO ?"; break;
        case 168 : texte = "La tua spada triplica il suo potere e ora pu� riglettere fasci magici. Grandioso!*"; break;
        case 169 : texte = "Vuoi che migliori i tuoi guanti?**              SI' ?            no  "; break;
        case 170 : texte = "Vuoi che migliori i tuoi guanti?**              s�               NO ?"; break;
        case 171 : texte = "Il potere dei tuoi guanti ora ti permette di sollevare le roccie pesanti!"; break;
        case 172 : texte = "Vuoi che migliori il tuo arco?**              SI' ?            no  "; break;
        case 173 : texte = "Vuoi che migliori il tuo arco?**              s�               NO ?"; break;
        case 174 : texte = "Il tuo arco ora pu� lanciare frecce d'argento dal potere devastante!"; break;
        case 175 : texte = "Torna quando avrai una bottiglia vuota e ti vender� una pozione blu che ripristina salute e carica magica."; break;
        case 176 : texte = "Una pozione blu per 160 rupie. Sei interessato?*              SI' ?            no  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=175; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<160) idsuiv=29;
            else idsuiv=108; break;
        case 177 : texte = "Una pozione blu per 160 rupie. Sei interessato?*              s�              NO ?"; break;
        case 178 : texte = "Il nostro villaggio � stato costruito qui per evitare che avventurieri imprudenti raggiungano il tempio. Non lascer� passare chiunque."; break;
        case 179 : texte = "Mmmm... Hai gi� trovato 4 cristalli?*Devo ammetterlo, mi hai impressionato...";
            buffer = "Bene, hai il permesso di attraversare il cimitero, ma a tuo rischio."; break;
        case 181 : texte = "Parla con la guardia a nord del villaggio. Ti lascer� passare."; break;
        case 182 : texte = "Vedo che sei ancora vivo...*Surprendente."; break;
        case 183 : texte = "Il tempio oscuro � il punto di partenza per la via che porta a un oggetto leggendario. Questo villaggio esiste unicamente per dissuadere gli avventuri dall'avvicinarcisi."; break;
        case 184 : texte = "Cos� hai trovato la spada?*Ma... non pensare che ti appartenga.";
            buffer = "La Spada Suprema � uno dei pi� preziosi patrimoni di Hyrule insieme alla Triforza. Dovrai riportarla al suo santuario una volta completata la tua missione."; break;
        case 186 : texte = "Tutti gli abitanti del villaggio sono spiriti che hanno risposto al richiamo della Principessa Zelda."; break;
        case 187 : texte = "Quando riportasti la pace in Hyrule e riunisti il Mondo della Luce con la Landa Dorata, Zelda in segreto chiese a degli spititi volontari di creare questo villaggio per bloccare";
            buffer = "l'accesso ad un oggetto di altissimo valore."; break;
        
        case 189 : texte = "Benvenuto Link!*Lascia che ti spieghi cosa sto facendo qui."; idsuiv=190; break;
        case 190 : texte = "Come certamente avrai notato, dei mostri sono apparsi in Hyrule. E' la prima volta che vedo dei mostri dai tempi della vittoria su Ganon."; idsuiv=191; break;
        case 191 : texte = "Ho deciso di catalogarli tutti."; idsuiv=192; break;
        case 192 : texte = "Sfortunatamente, sono troppo pauroso per incontrarli, quindi ho bisogno del tuo aiuto."; idsuiv=193; break;
        case 193 : texte = "Devi sconfiggere ogni tipo di mostro e venire a farmi un resoconto."; idsuiv=194; break;
        case 194 : texte = "ogni volta che avrai sconfitto 7 nuovi tipi di mostro, di dar� una parte di cuore."; idsuiv=195; break;
        case 195 : texte = "Se vuoi vedere quali nemici hai gi� sconfitto, premi i tasti L e B."; break;
        
        
        case 196 : 
            if (gpJeu->getJoueur()->getCoeur(43)) {
                if (gpJeu->getJoueur()->nbEnnemis() >= 46) {id=205; chercheText();return;}
                else {id=204; chercheText();return;}
            }
            for (int i = 38; i < 44; i++) 
                if (!gpJeu->getJoueur()->getCoeur(i) 
                && (gpJeu->getJoueur()->nbEnnemis()/7)+37>=i) {
                    id=203; chercheText();return;
                }
            tmp = 7-(gpJeu->getJoueur()->nbEnnemis()%7);
            os << tmp;
            if (tmp>1) texte = "Hai bisogno di "+os.str()+" mostri differenti ancora prima della tua prossima ricompensa.";
            else texte = "Te ne serve solo uno ancora prima della tua prossima ricompensa!";
            break;
        case 203 : texte = "Prendi questo dono come ringraziamento per il tuo contributo al mio progetto:"; break;
        case 204 : texte = "Spiacente, ma non ho pi� nulla per te."; break;
        case 205 : texte = "Non posso crederci, sei riuscito a sconfiggere tutti i tipi di nemici!*Congratulazioni, Link!"; break;
        
        case 206 : texte = "                   Livello 1:**              Tempio della Foresta"; break;
        case 207 : texte = "                   Livello 2:**               Tempio dell'Acqua"; break;
        case 208 : texte = "                   Livello 3:**              Tempio della Montagna"; break;
        case 209 : texte = "                   Livello 4:**               Tempio del Deserto"; break;
        case 210 : texte = "                   Livello 5:**                  Tempio Oscuro"; break;
        case 211 : texte = "                   Livello 6:**                 Tempio del Fuoco"; break;
        case 212 : texte = "                   Livello 7:**                Tempio di Ghiaccio"; break;
        case 213 : texte = "                   Livello ?:**                  Tempio Segreto"; break;
        case 214 : texte = "                 Ultimo livello:**             Castello di Hyrule"; break;
        
        case 215 :texte = "                  Gi� stanco?                    ?                 CONTINUA                 ?                   Salva e esci                                Esci senza salvare             "; break;
        case 216 :texte = "                  Gi� stanco?                                      Continua                     ?               SALVA E ESCI               ?                Esci senza salvare             "; break;
        case 217 :texte = "                  Gi� stanco?                                      Continua                                     Salva e esci                   ?            ESCI SENZA SALVARE            ?"; break;
        
        case 223 : texte = "Nell'istante in cui Link tocc� la Triforza, i mostri sparirono e la pace ritorn�.**La Principessa Zelda allora prese una importante decisione: tocc� la Triforza ed espresse il suo desiderio.**La Triforza era sempre stata l'origine dei problemi del regno. Prima o poi un'altra creatura malvaggia l'avrebbe trovata.**Quando la Principessa Zelda tocc� la reliquia, questa spar� da Hyrule... per sempre.";
            buffer = "Da quel giorno gli abitanti di Hyrule vissero in pace, senza temere nuovi disastri.**Cos� la leggenda di Zelda, della Triforza e della Landa D'Oro si � conclusa**La Spada Suprema si dice riposi al sicuro da qualche parte e che sia l'unico cimelio rimasto delle gesta di Link."; break;
        case 224 : texte = "Congratulazioni per avermi trovato, Link. Come ricompensa ti dono il pendente di Farore. Aumenta la tua difesa di un punto."; break;
        case 225 : texte = "Vuoi salvare la partita?     **                    ? SI' ?*                      no  "; break;
        case 226 : texte = "Vuoi salvare la partita?     **                      s�   *                    ? NO ?"; break;
        case 227 : texte = "Partita salvata."; break;
        
        case 228 : texte = "Il regno di Hyrule � stato in pace sin da quando Link, l'ultimo cavaliere di Hyrule, ha sconfitto il malefico Ganon e recuperato la preziosa Triforza."; idsuiv = 229; break;
        case 229 : texte = "nessuno sa quale desiderio abbia espresso Link alla Triforza, ma ha avuto l'effetto di riunificare i mondi della luce e dell'oscurit�, e di resuscitare i discendenti dei 7 saggi."; idsuiv = 230; break;
        case 230 : texte = "Link in seguito affid� la Triforza e la Spada Suprema alla Principessa Zelda, e le persone cominciarono a credere che la pace sarebbe durata per sempre.*Ma si sbagliavano..."; idsuiv=231; break;
        case 231 : texte = "Sfortunatamente infatti il desiderio espresso da Link ebbe anche effetti negativi. Anche Ganon e i suoi scagnozzi erano resuscitati e furono presto di nuovo pronti all'attacco."; idsuiv=232; break;
        case 232 : texte = "In qualche posto nella foresta di Hyrule, Link sta dormendo senza sospettare che Ganon ha gi� iniziato il suo attacco, quando una voce familiare gli parla nel sonno..."; break;
        case 233 : texte = "Aiutami!*Aiutami!*Sono io! Zelda!*Ti sto parlando telepaticamente."; idsuiv = 234; break;
        case 234 : texte = "Sono prigioniera nelle segrete del castello!*Ho bisogno del tuo aiuto!*Ganon � tornato, e sicuramente ha gi� trovato la Triforza..."; idsuiv=235; break;
        case 235 : texte = "Vieni di corsa al castello, Link! Sei la mia unica speranza..."; break;
        case 236 : texte = "SUGGERIMENTO: Premi L e Y per consultare il menu di aiuto."; break;
    }
	break; // Italian

case 5: // Spanish

    switch (id) {
        case 1  : texte = "Has encontrado un escudo !!!**Tu defensa aumenta de un punto!"; break;
        case 2  : texte = "Has encontrado una espada !!!**Ahora puedes defenderte contra los monstros con la tecla B !!!*Manten B para descargar el giratorio !"; break;
        case 3  : 
            tmp = 4-(gpJeu->getJoueur()->nbQuarts()%4);
            os << tmp;
            texte = "Has encontrado un cuarto de coraz�n !!!";
            if (tmp<4) buffer = "Con "+os.str()+" mas obtendras un coraz�n adicional !!!";
            else buffer = "Tu numero de coraz�nes acaba de aumentar !!!";
            break;
        case 11 : texte = "N : Casa de Link*O : Finca de Hyrule*E : Templo del Bosque"; break;
        case 12 : texte = "Templo de la Monta�a**No aconsejado para cardiacos, miedosos, y emotivos en general."; break;
        case 13 : texte = "O : Entrada del desierto*N : Templo de la Monta�a"; break;
        case 14 : texte = "N : Templo de la Monta�a*S : Finca de Hyrule"; break;
        case 15 : texte = "N : Monta�a de la Muerte"; break;
        case 16 : texte = "E : Entrada del Bosque"; break;
        case 17 : texte = "S : Lago de Hylia*E : Cementerio de los Esp�ritus"; break;
        case 18 : texte = "S : Hacia el pueblo Kakariko"; break;
        case 19 : texte = "N : Pueblo Kakariko"; break;
        case 20 : texte = "N : Finca de Hyrule"; break;
        case 21 : texte = "O : Tierras de Fuego"; break;
        case 22 : texte = "E : Pueblo de la Sombra*- Prohibido a los seres vivos -"; break;
        case 23 : texte = "Templo de las tinieblas**Si eres un fantasma y que buscas un trabajo, m�s bien vente a estar parado aqu�."; break;
        case 24 : texte = "N : Pueblo de la Sombra*O : Lago de Hylia"; break;
        case 25 : texte = "N : Cementerio de los Esp�ritus**Entrada prohibida"; break;
        case 26 : texte = "Pueblo de la Sombra"; break;
        case 27 : texte = "Vendo una botella por 100 rupias, quieres ?*              SI ?            no  "; 
            if ((gpJeu->getJoueur()->hasBouteille(0) && gpJeu->getZone()==8)
            || (gpJeu->getJoueur()->hasBouteille(1) && gpJeu->getZone()==5)
            || (gpJeu->getJoueur()->hasBouteille(2) && gpJeu->getZone()==6)) {id=32; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<100) idsuiv=29;
            else idsuiv=30;
            break;
        case 28 : texte = "Vendo una botella por 100 rupias, quieres ?*              si              NO ?"; idsuiv=31; break;
        case 29 : texte = "Lo siento, pero no tienes bastantes rupias."; break;
        case 30 : texte = "Muchas gracias, he aqu� tu botella."; break;
        case 31 : texte = "Vuelve si cambias de opini�n."; break;
        case 32 : texte = "Lo siento, no tengo m�s botellas."; break;
        case 33 : texte = "Has encontrado una botella vac�a !!!**Podr�s utilizarla para almacenar pozimas !!!"; break;
        case 35 : texte = "Los habitantes de este pueblo tienen un dialecto muy especial, no entiendo nada..."; break;
        case 36 : texte = "@+@+@+@+@+@+@@@+*@=++=@=+@=+@=+=@*+@+@+@+=+="; break;
        case 37 : texte = "Obten una autorization del jefe si quieres pasar de verdad !!!"; break;
        case 38 : texte = "El jefe te autoriz� ??? Grrrr... Pues apartate!!!"; break;
        case 39 : texte = "Fuera de aqu� !!!"; break;
        case 40 : texte = "No solemos ver muchos visitantes por aqu�..."; break;
        case 41 : texte = "Los monstruos de aqu� no temen muchas cosas, por suerte atacan solo los humanos."; break;
        case 42 : texte = "De verdad ?*Entiendes lo que digo ?"; break;
        case 43 : texte = "N : Desierto y Pueblo Gerudo"; break;
        case 44 : texte = "S : Lago de Hylia*O : Castillo de Hyrule"; break;
        case 45 : texte = "Pueblo Kakariko"; break;
        case 46 : texte = "O : Castillo de Hyrule"; break;
        case 47 : texte = "Que d�a tan bueno !!!"; break;
        case 48 : texte = "Pero porque acept� cuidar estos bichos ???*Odio las gallinas !!!"; break;
        case 49 : texte = "Se encuentran muchas cosas en las tiendas de este pueblo."; break;
        case 50 : texte = "S : Pueblo Kakariko*O : Desierto*E : Monta�a de la Muerte"; break;
        case 51 : texte = "Pueblo Gerudo"; break;
        case 52 : texte = "Perdido en el desierto ?*Estas aqu� :*                        X"; break;
        case 54 : texte = "S : Hacia el Castillo de Hyrule"; break;
        case 55 : texte = "Templo del Desierto**Ven a probar nuestros ba�os.*(agua no potable)"; break;
        case 56 : texte = "Templo del Bosque**Salve los �rboles, coma castor!!!"; break;
        case 57 : texte = "Templo del Lago**Gorro de ba�o obligatorio."; break;
        case 58 : texte = "Templo de Hielo**El personal insiste en recordar que un calabozo no es una pista de patinaje."; break;
        case 59 : texte = "Has visto el herrero del pueblo ?*Dicen que es muy avispado para mejorar el equipo de los aventureros, mucha gente le visita."; break;
        case 60 : texte = "El templo esta en el fondo del desierto, en puesto de una antigua oasis."; break;
        case 61 : texte = "S : Tierras de Fuego*E : Pueblo Kakariko"; break;
        case 62 : texte = "Castillo de Hyrule"; break;
        case 63 : texte = "E : Pueblo Kakariko"; break;
        case 64 : texte = "O : Tortuga de Roca*E : Lago de Hylia"; break;
        case 65 : texte = "Templo Oculto**Aqu� descansa la Espada del Golpe Contra el Mal, la Espada Maestra."; break;
        case 66 : texte = "N : Hacia el Cimenterio encantado"; break;
        case 67 : texte = "Has encontrado el mapa del calabozo !!!*Pulsa START para verlo."; break;
        case 68 : texte = "Has encontrado la br�jula !!!*Puedes localizar el jefe y las arcas sobre el mapa."; break;
        case 69 : texte = "Has encontrado la llave del jefe !!!"; break;
        case 70 : texte = "Has encontrado una llave peque�a !!!*Acercate de una puerta para abrirla."; break;
        case 71 : texte = "Has encontrado los Guantes !!!*Utilizalos para levantar objetos equipandolos o pulsando X."; break;
        case 72 : 
            texte = "Has encontrado un cristal magico !!!"; 
            tmp = 7-gpJeu->getJoueur()->nbCristaux();
            os << tmp;
            if (tmp==6 && !gpJeu->getJoueur()->getAvancement()) buffer = "C�mo podr�a ser �til... ?";
            else if (tmp>2) buffer = "Te quedan a�n "+os.str()+" por encontrar !!!";
            else if (tmp==2) buffer = "Solo 2 que encontrar !!!";
            else if (tmp==1) buffer = "Te falta solo uno !!!";
            else if (tmp==0) buffer = "Tienes todo los cristales, corre hasta el castillo a salvar a Zelda !!!";
            break;
        case 80 : texte = "Has encontrado el lanzagarfios !!! *Utilizalo para atravesar obst�culos."; break;
        case 81 : texte = "Has encontrado la lampara !!! *Utilizala para hacer surgir llamas."; break;
        case 82 : texte = "Has encontrado las aletas !!! *Equipalas para ir en el agua."; break;
        case 83 : texte = "Has encontrado el martillo m�gico !!! *Utilizalo para hundir obst�culos."; break;
        case 84 : texte = "Has encontrado la varilla de fuego !!! *De ahora en adelante puedes lanzar potentes llamas remotas"; break;
        case 85 : texte = "Has encontrado la varilla de hielo !!! *Utilizala para congelar todo a distancia."; break;
        case 86 : texte = "Has encontrado la Espada Maestra !!! *Incluso Ganon no deber�a ser capaz de resistir a su potencia !!! (en teor�a)"; break;
        case 87 : texte = "Felicitaciones Link, has conseguido venir a liberarme!!!***Vamonos de prisa a encontrar a Ganon, tenemos que retomar la Trifuerza a toda costa !"; break;
        case 89 : texte = "El paso secreto detr�s de la sala del trono lleva a Ganon. Vamos rapido !"; break;
        case 90 : texte = "Casi hemos llegado, sigueme !"; break;
        case 91 : texte = "Tengo miedo que no puedas nunca vencer a Ganon con tus armas actuales...*Ve a hablar con el jefe del pueblo Kakariko, estoy segura que �l va a encontrar una soluci�n."; break;
        case 92 : texte = "Ganon esta ya detr�s de esta puerta, voy a curarte las heridas."; break;
        case 93 : texte = "Ganon todav�a esta en alg�n sitio del castillo."; break;
        case 94 : texte = "Tendr�as que esperar a la princesa Zelda !!!"; break;
        case 95 : texte = "No tienes la extra�a impresi�n de olvidar a alguien por casualidad ???"; break;
        case 96 : texte = "Zelda te esta esperando!!!"; break;
        case 97 : texte = "Has encontrado la Trifuerza!!!"; break;
        case 98 : texte = "Has encontrado el libro de Mudora!!! **Ahora entiendes el hyliano antiguo!!!"; break;
        case 99 : texte = "Felicitaciones Link, has conseguido encontrarme. En recompensa, te ofrezco el pendiente de Din, aumenta tu defensa de un punto."; break;
        case 100 : texte = "Felicitaciones Link, has conseguido encontrarme. En recompensa, te ofrezco el pendiente de Nayru, aumenta tu defensa de dos puntos!!!"; break;
        case 101 : texte = "..."; break;
        case 102 : texte = "Has obtenido un pendiente m�gico !!!**Tu defensa acaba de aumentar!!!"; break;
        case 103 : texte = "Felicitaciones Link, has conseguido encontrarme. Para recompensarte, voy a doblar la capacidad de tu reserva de magia!!!"; break;
        case 104 : texte = "Tu reserva de magia ha doblado!!!"; break;
        case 105 : texte = "Vuelve cuando tengas una botella vac�a  y te vender� una pozima roja que te devuelve la energia."; break;
        case 106 : texte = "Una pozima roja por 60 rupias, la quieres ?*              SI ?            no  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=105; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<60) idsuiv=29;
            else idsuiv=108; break;
        case 107 : texte = "Una pozima roja para 60 rupias, la quieres ?*              si              NO ?"; break;
        case 108 : texte = "Gracias, toma tu pozima.";break;
        case 109 : texte = "Has obtenido una pozima roja !!!*Bebela para renovar tu energia!!!"; break;
        case 110 : texte = "Has obtenido una pozima verde !!!*Bebela para renovar tu magia!!!"; break;
        case 111 : texte = "Has obtenido una pozima azul !!!*Bebela para renovar tu energia y tu magia!!!"; break;
        case 112 : texte = "Ola, en que puedo ayudarle ?"; break;
        case 113 : texte = "Hic! Dicen que una hada dar�a objetos encantados... Hic! ...a los aventureros que la encuentran... Hic!!!"; break;
        case 114 : texte = "Un coraz�n por 10 rupias, vale ?**              SI ?            no  "; 
            if (gpJeu->getJoueur()->getVie()+gpJeu->getJoueur()->getBoostVie()
            == gpJeu->getJoueur()->getVieMax()) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29;
            else idsuiv=129; break;
        case 115 : texte = "Un coraz�n por 10 rupias, vale ?**             si              NO ?"; break;
        case 116 : texte = "Un poco de magia por 20 rupias, vale ?**              SI ?            no  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<20) idsuiv=29;
            else idsuiv=129; break;
        case 117 : texte = "Un poco de magia por 20 rupias, vale ?**              si              NO ?"; break;
        case 118 : texte = "Mucho magia por 30 rupias, vale ?**              SI ?            no  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 119 : texte = "Mucho magia por 30 rupias, vale ?**              si              NO ?"; break;
        case 120 : texte = "5 flechas por 30 rupias, vale ?**              SI ?            no  "; 
            if (gpJeu->getJoueur()->getFleche() == gpJeu->getJoueur()->getFlecheMax() 
            || !gpJeu->getJoueur()->hasObjet(O_ARC)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 121 : texte = "5 flechas por 30 rupias, vale ?**              si              NO ?"; break;
        case 122 : texte = "Una bomba por 30 rupias, vale ?**              SI ?            no  "; 
            if (gpJeu->getJoueur()->getBombe() == gpJeu->getJoueur()->getBombeMax() 
            || !gpJeu->getJoueur()->hasObjet(O_SAC_BOMBES)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 123 : texte = "Una bomba por 30 rupias, vale ?**              si              NO ?"; break;
        case 124 : texte = "Un arco por 1000 rupias, vale ?**              SI ?            no  "; 
            idsuiv=29; break;
        case 125 : texte = "Un arco por 1000 rupias, vale ?**              si              NO ?"; break;
        case 126 : texte = "Un arco por 50 rupias, vale ?**              SI ?            no  "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<50) idsuiv=29;
            else idsuiv=129; break;
        case 127 : texte = "Un arco por 50 rupias, vale ?**              si              NO ?"; break;
        case 128 : texte = "No necesitas eso ahora."; break;
        case 129 : texte = "Gracias."; break;
        case 130 : texte = "Has obtenido el arco !!!*Utilizalo para alcanzar objetivos alejados."; break;
        case 131 : texte = "Elige lo que quieras."; break;
        case 132 : texte = "Que ???*Estas en contratado por el jefe ???*Pues vale, te hago une reducci�n sobre el arco..."; break;
        case 133 : texte = "Buenos d�as Link, soy el jefe de este pueblo, me figuraba que vendri�s."; idsuiv=134; break;
        case 134 : texte = "Desde esta ma�ana monstruos aparecen en muchas partes de Hyrule, he intentado ir a hablar de eso con la princesa Zelda, pero como quiz�s ya lo has notado, un poderoso hechizo bloquea el acceso al castillo..."; idsuiv=136; break;
        case 136 : texte = "Dices que Ganon es responsable de todo esto ? Que ha robado la Trifuerza y que encarcela la princesa Zelda en el castillo ?"; idsuiv=137; break;
        case 137 : texte = "Pues... la situaci�n es mucho m�s grave que lo que cre�a..."; idsuiv=138; break;
        case 138 : texte = "Tenemos que obrar rapidamente, debes enfrentar a Ganon de nuevo!"; idsuiv=139; break;
        case 139 : texte = "C�mo entrar en el castillo ? Quiz�s tenga una idea..."; idsuiv=140; break;
        case 140 : texte = "Como lo sabes, el poder de los 7 Hombres Sabios fue encerrado en 7 cristales por el mago Aghanim mientras intentaba quitar el hechizo que confinaba Ganon en el Dark World."; idsuiv=141; break;
        case 141 : texte = "Ahora bien, aunque resucitaste las descendientes de los hombres sabios despues de vencer a Ganon y de encontrar la Trifuerza, estos cristales conservaron sus potencia."; idsuiv=142; break;
        case 142 : texte = "Estan escondidos en los 7 templos, re�nelos todos y podr�s ir m�s all� del sortilego de Ganon."; idsuiv=143; break;
        case 143 : texte = "Sin embargo, ser� una tarea muy dura, Ganon sin duda ha debido de enviar sus mejores unidades a proteger esos cristales..."; idsuiv=144; break;
        case 144 : texte = "Una ultima cosa, no ir�s muy lejos con tu equipo actual. Ve a ver al vendedor de armas y dile que vienes de mi parte. Seguro que tu ayudar�."; break;
        case 145 : texte = "Ve a ver el vendedor de armas y dile que vienes de mi parte. Seguro que tu ayudar�."; break;
        case 146 : texte = "Tienes que reunir los 7 cristales si quieres tener una posibilidad de salvar a Zelda y Hyrule..."; break;
        case 147 : texte = "Has encontrado los 7 cristales ?  Ve al castillo, primero debes liberar a la princesa, ella sabr� mejor que yo c�mo salvar Hyrule."; break;
        case 148 : texte = "Tus armas no tienen efecto sobre Ganon ? En este caso tienes que encontrar la Espada Maestra. Se dice que fue disimulada en un templo secreto.*Se dice tambien que el camino que conduce a la Espada del Golpe Contra el Mal pasa por un pueblo lleno de monstros...*Me pregunto si tal pueblo existe..."; break;
        case 150 : texte = "No obstante tengo miedo que tu equipo actual sea insuficiente para acceder a este templo, a lo mejor deber�as ir a ver al herrero del pueblo Gerudo..."; break;
        case 151 : texte = "Ya es hora de enfrentarse a Ganon y de recuperar la Trifuerza!"; break;
        case 152 : texte = "Hey! Hay que pagar para abrir una de mis arcas!!!"; break;
        case 153 : texte = "Una de estas arcas contiene un cuarto de coraz�n, quieres probar tu fortuna por 10 rupias ? Podr�s abrir solo una, vale ?*              SI ?            no  "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29; break;
        case 154 : texte = "Una de estas arcas contiene un cuarto de coraz�n, quieres probar tu fortuna por 10 rupias ? Podr�s abrir solo una, vale ?*              si              NO ?"; break;
        case 155 : texte = "Elige un arca."; break;
        case 156 : texte = "No tengo m�s premios que poner en juego, lo siento."; break;
        case 157 : texte = "Has perdido! Este arca esta vac�a."; break;
        case 158 : texte = "Buenos d�as! Si estas aqu� para ver el herrero, vive un poco m�s lejos."; break;
        case 159 : texte = "Ola Link, soy el jefe de este pueblo.*Deber�as ir a ver el herrero y monstrarle lo que quieres que mejore en tu equipo.";
            buffer = "He sido informado de tu b�squeda, entonces me puse de acuerdo con el.*Todo ser� gratis para ti."; break;
        case 160 : texte = "No necesitas beber esta pozima ahora."; break;
        case 161 : texte = "Una pozima verde por 40 rupias, la quieres ?*              SI ?            no  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=163; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<40) idsuiv=29;
            else idsuiv=108; break;
        case 162 : texte = "Una pozima verde por 40 rupias, la quieres ?*              si              NO ?"; break;
        case 163 : texte = "Vuelve cuando tengas una botella vac�a y te vender� una pozima verde que rellena la magia."; break;
        case 164 : texte = "Vuelve m�s tarde, estoy agobiado!"; break;
        case 165 : texte = "Puedo hacer algo para ti ?";
            if (gpJeu->getJoueur()->getEpee()==1) {id=166; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_GANTS)==1 && gpJeu->getJoueur()->getObjet()==8) {
                id=169; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_ARC)==2 && gpJeu->getJoueur()->getObjet()==0 
            && gpJeu->getJoueur()->nbCristaux()==7) {
                id=172; chercheText();break;}
            break;
        case 166 : texte = "Quieres que mejore tu espada ?**              SI ?            no  "; break;
        case 167 : texte = "Quieres que mejore tu espada ?**              si              NO ?"; break;
        case 168 : texte = "Tu espada ha triplicado de potencia y puede ahora devolver algunos ataques magicos, guay!!!"; break;
        case 169 : texte = "Quieres que mejore tus guantes ?**              SI ?            no  "; break;
        case 170 : texte = "Quieres que mejore tus guantes ?**              si              NO ?"; break;
        case 171 : texte = "La potencia de tus guantes te permite ahora levantar rocas pesadas."; break;
        case 172 : texte = "Quieres que mejore tu arco ?**              SI ?            no  "; break;
        case 173 : texte = "Quieres que mejore tu arco ?**              si              NO ?"; break;
        case 174 : texte = "Tu arco tira ahora flechas de plata de una potencia devastadora !!!"; break;
        case 175 : texte = "Vuelve cuando tengas una botella vac�a y te vender� una pozima azul que rellena la energia y la magia."; break;
        case 176 : texte = "Una pozima azul por 160 rupias, la quieres ?*              SI ?            no  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=175; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<160) idsuiv=29;
            else idsuiv=108; break;
        case 177 : texte = "Una pozima azul por 160 rupias, la quieres ?*              si              NO ?"; break;
        case 178 : texte = "Nuestro pueblo fue fundado para impedir a los aventureros imprudentes que tengan acceso al templo, no da el permiso para pasar a cualquiera."; break;
        case 179 : texte = "Mmmm... Ya has encontrado 4 cristales ?*Tengo que confesar que me impresionas...";
            buffer = "Pues entendido, tienes el permiso para pasar por el cementerio, por tu cuenta y riesgo."; break;
        case 181 : texte = "Ve a hablar al guardia al norte del pueblo, te dejar� pasar."; break;
        case 182 : texte = "Veo que siempre estas vivo...*Sorprendente."; break;
        case 183 : texte = "El templo de las tinieblas es el punto de partida del camino que conduce a un objeto de leyenda. Este pueblo solo sirve para disuadir a los aventureros de acercarse demasiado."; break;
        case 184 : texte = "Has encontrado la Espada ?*Pero no creas que es tuya por eso.";
            buffer = "La Espada Maestra forma parte del patrimonio el m�s valioso de Hyrule con la Trifuerza, tendr�s que devolverla en su santuario en cuanto acabes tu misi�n."; break;
        case 186 : texte = "Los habitantes de este pueblo son todos esp�ritus que han contestado a la llamada de la princesa Zelda."; break;
        case 187 : texte = "Cuando devolviste la paz sobre Hyrule y reunificaste el Light World con el Golden Land, Zelda pregunt� en secreto a los esp�ritus voluntarios que crean este pueblo para bloquear";
            buffer = "el acceso a un objeto muy valioso."; break;
        
        case 189 : texte = "Bienvenido Link!*Dejame explicarte lo que hago aqu�."; idsuiv=190; break;
        case 190 : texte = "Como ya lo has notado sin duda, monstruos han aparecido por todas partes en Hyrule. Es la primera vez que veo monstruos despues que venciste a Ganon."; idsuiv=191; break;
        case 191 : texte = "Pues he decidido catalogarlos todos."; idsuiv=192; break;
        case 192 : texte = "El problema es que soy demasiado miedoso para ir al encuentro de ellos, necesito tu ayuda."; idsuiv=193; break;
        case 193 : texte = "Tienes que golpear cada tipo de monstruo y venir a hacerme tu informe."; idsuiv=194; break;
        case 194 : texte = "Te recompensar� cada vez que mates 7 nuevos tipos de enemigo."; idsuiv=195; break;
        case 195 : texte = "Si quieres ver que enemigos ya has vencido, pulsa L y B."; break;
        
        
        case 196 : 
            if (gpJeu->getJoueur()->getCoeur(43)) {
                if (gpJeu->getJoueur()->nbEnnemis() >= 46) {id=205; chercheText();return;}
                else {id=204; chercheText();return;}
            }
            for (int i = 38; i < 44; i++) 
                if (!gpJeu->getJoueur()->getCoeur(i) 
                && (gpJeu->getJoueur()->nbEnnemis()/7)+37>=i) {
                    id=203; chercheText();return;
                }
            tmp = 7-(gpJeu->getJoueur()->nbEnnemis()%7);
            os << tmp;
            if (tmp>1) texte = "Con "+os.str()+" mas enemigos diferentes tendras la proxima recompensa.";
            else texte = "Te falta solo uno nuevo enemigo antes de la proxima recompensa!!!";
            break;
        case 203 : texte = "Acepta este regalo por tu contribuci�n en mi proyecto :"; break;
        case 204 : texte = "Lo siento pero no tengo nada m�s que regalarte..."; break;
        case 205 : texte = "No me le puedo creer, has conseguido vencer cada tipo de enemigo !!!*Felicitaciones Link !!!"; break;
        
        case 206 : texte = "                    Nivel 1 :**               Templo del Bosque"; break;
        case 207 : texte = "                    Nivel 2 :**                Templo del Agua"; break;
        case 208 : texte = "                    Nivel 3 :**              Templo de la Monta�a"; break;
        case 209 : texte = "                    Nivel 4 :**              Templo del Desierto"; break;
        case 210 : texte = "                    Nivel 5 :**            Templo de las Tinieblas"; break;
        case 211 : texte = "                    Nivel 6 :**                Templo del Fuego"; break;
        case 212 : texte = "                    Nivel 7 :**                Templo de Hielo"; break;
        case 213 : texte = "                    Nivel ? :**                 Templo Oscuro"; break;
        case 214 : texte = "                  Nivel Final :**               Castillo de Hyrule"; break;
        
        case 215 :texte = "               Ya estas cansado ?               ?                   SEGUIR                  ?                  Grabar y dejar                                Dejar sin grabar              "; break;
        case 216 :texte = "               Ya estas cansado ?                                   Seguir                     ?               GRABAR Y DEJAR              ?                 Dejar sin grabar              "; break;
        case 217 :texte = "               Ya estas cansado ?                                   Seguir                                     Grabar y dejar                 ?              DEJAR SIN GRABAR             ?"; break;
        
        case 223 : texte = "En el momento en que Link toc� la Trifuerza, los monstruos desaparecieron y la paz volvi�.**La princesa Zelda tom� entonces una gran decisi�n: toc� a su vez la Trifuerza para formular su deseo...**La Trifuerza siempre fue el origen de los problemas sobrevenidos en el Reino,  tarde o temprano una otra criatura da�ina habr�a acabado encontrandola.**Al mismo tiempo que la princesa toc� la reliquia, desapareci� para siempre de Hyrule.";
            buffer = "Desde ese d�a, el pueblo de Hyrule vivi� en paz, sin temer nuevos desastres.**Asi se acaba la leyenda de Zelda, de la  Trifuerza y del Golden Land.**Se dice que la Espada Maestra descansa en seguridad en cualquier lugar, y que es el ultimo recuerdo de la b�squeda de Link..."; break;
        case 224 : texte = "Felicitaciones Link, has conseguido encontrarme. En recompensa, te ofrezco el pendiente de Farore, aumenta tu defensa de un punto."; break;
        case 225 : texte = "Quieres grabar tu juego ?**                      ? SI ?*                        no  "; break;
        case 226 : texte = "Quieres grabar tu juego ?**                        si  *                      ? NO ?"; break;
        case 227 : texte = "Juego grabado."; break;
        
        case 228 : texte = "El Reino de Hyrule estaba en paz desde que Link, ultimo cavallero hyliano, hab�a vencido el mal�fico Ganon y hab�a recuperado la valiosa Trifuerza."; idsuiv = 229; break;
        case 229 : texte = "Nadie sabe que deseo hizo Link tocando la Trifuerza, pero tuvo como efecto de reunificar el Light World y el Dark World, y volvi� a los descendientes de los 7 Hombres Sabios a la vida."; idsuiv = 230; break;
        case 230 : texte = "Despues Link devolvi� a la princesa Zelda la Trifuerza y la Espada Maestra, y el pueblo se puso a creer que la paz duraria.*Pero el pueblo se equivocaba..."; idsuiv=231; break;
        case 231 : texte = "El deseo de Link a la Trifuerza igualmente tuvo lamentables efectos. Ganon y sus esbirros fuen asi resucitados y se dispusieron a atacar."; idsuiv=232; break;
        case 232 : texte = "En alguna parte del bosque de Hyrule, Link duerme sin sospechar que Ganon ya ha pasado al ataque, hasta que una voz familiar le habla en su sue�o..."; break;
        case 233 : texte = "Ayuda!*Ayuda!*Soy yo! Zelda!*Te hablo por telepat�a."; idsuiv = 234; break;
        case 234 : texte = "Estoy prisionera en el torre�n del castillo! Necesito tu ayuda!*Ganon esta de vuelta, y sin duda ya ha encontrado la Trifuerza a estas horas..."; idsuiv=235; break;
        case 235 : texte = "Corre al castillo Link, eres mi �nica esperanza..."; break;
        case 236 : texte = "AYUDA : Pulsa L y Y para consultar la ayuda."; break;
    }

break; // Spanish

case 6: // Hungarian
// //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHhh //UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUuuuu

switch (id) {
        case 1  : texte = "Tal�lt�l egy pajzsot!**A v�delmed n�vekszik 1 ponttal!"; break;
        case 2  : texte = "Tal�lt�l egy kardot!**Most m�r harcolhatsz sz�rnyekkel a B gombbal.*Tartsd nyomva a B gombot, hogy felt�ltsd a forg� t�mad�st!"; break;
        case 3  : 
            tmp = 4-(gpJeu->getJoueur()->nbQuarts()%4);
            os << tmp;
            texte = "Tal�lt�l egy sz�vdarabot!!!";
            if (tmp<4) buffer = "M�g "+os.str()+" darabra van sz�ks�ged egy �j sz�vt�rol�hoz.";
            else buffer = "A sz�v szinted n�vekedett!";
            break;
        case 11 : texte = "�: Link otthona*NY: Hyrule fenns�k*K: Erd� temploma"; break;
        case 12 : texte = "Hegyi templom**Nem a sz�vbajosak, ijed�sek �s a gyenge sz�v�ek sz�m�ra."; break; 
        case 13 : texte = "NY: Sivatag bej�rat*�: Hegyi templom"; break;
        case 14 : texte = "�: Hegyi templom*D: Hyrule fenns�k"; break;
        case 15 : texte = "�: Hal�l hegys�g"; break;
        case 16 : texte = "K: Erd� bej�rat"; break;
        case 17 : texte = "D: Hylia t�*K: K�s�rtetj�rta temet�"; break;
        case 18 : texte = "D: Kakariko falu fel�"; break;
        case 19 : texte = "�: Kakariko falu"; break;
        case 20 : texte = "�: Hyrule fenns�k"; break;
        case 21 : texte = "NY: T�z f�ld"; break;
        case 22 : texte = "K: �rny falu*- Nem az �l�knek -"; break;
        case 23 : texte = "S�t�t templom**Ha szellem vagy �s munk�t keresel, gyere ide �s l�gj vel�nk."; break;
        case 24 : texte = "�: �rny falu*NY: Hylia t�"; break;
        case 25 : texte = "�: K�s�rtetj�rta temet�**Nincs bel�p�s"; break;
        case 26 : texte = "�rny falu"; break;
        case 27 : texte = "100 r�pi��rt adok egy palackot, �rdekel?*             IGEN ?            nem  "; 
            if ((gpJeu->getJoueur()->hasBouteille(0) && gpJeu->getZone()==8)
            || (gpJeu->getJoueur()->hasBouteille(1) && gpJeu->getZone()==5)
            || (gpJeu->getJoueur()->hasBouteille(2) && gpJeu->getZone()==6)) {id=32; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<100) idsuiv=29;
            else idsuiv=30;
            break;
        case 28 : texte = "100 r�pi��rt adok egy palackot, �rdekel?*             igen              NEM ?"; idsuiv=31; break;
        case 29 : texte = "Sajn�lom, nincs el�g r�pi�d"; break;
        case 30 : texte = "K�sz�n�m, itt a palackod."; break;
        case 31 : texte = "Gyere m�skor, ha meggondoltad magad."; break;
        case 32 : texte = "Sajn�lom, ez volt az egyetlen �vegem."; break;
        case 33 : texte = "Tal�lt�l egy �res �veget!**J� lehet italok t�rol�s�ra."; break;
        case 35 : texte = "A falu lak�inak a szok�sost�l elt�r� a nyelvj�r�sa. Nem �rtek semmit ..."; break;
        case 36 : texte = "@+@+@+@+@+@+@@@+*@=++=@=+@=+@=+=@*+@+@+@+=+="; break;
        case 37 : texte = "Wangle f�n�k enged�lye kell, ha t�nyleg �t szeretne haladni!"; break; 
        case 38 : texte = "A f�n�k enged�lyezte az �talad�st? Grrrr... Akkor haladj tov�bb!"; break;
        case 39 : texte = "Menj az utamb�l!"; break;
        case 40 : texte = "Nem t�l s�r�n j�nnek l�togat�k errefel�."; break;
        case 41 : texte = "A helyi sz�rnyek nem sok mindet�l f�lnek. Szerencs�re csak embereket t�madnak meg."; break;
        case 42 : texte = "Val�ban?*Meg�rted amit mondok?"; break;
        case 43 : texte = "�: Sivatag �s Gerudo falu"; break; 
        case 44 : texte = "D: Hylia t�*NY: Hyrule kast�ly"; break;
        case 45 : texte = "Kakariko falu"; break;
        case 46 : texte = "NY: Hyrule kast�ly"; break;
        case 47 : texte = "Milyen sz�p nap!"; break;
        case 48 : texte = "Mi�rt v�llaltam el, hogy gondoskodom arr�l a szem�tr�l?* Ut�lom a ty�kokat!"; break;
        case 49 : texte = "Sok mindent tal�lhatsz ennek a falunak a boltj�ban."; break;
        case 50 : texte = "D: Kakariko falu*NY: Sivatag*K: Hal�l hegys�g"; break;
        case 51 : texte = "Gerudo falu"; break;
        case 52 : texte = "Elt�vedt�l a sivatagban?*Itt vagy:*                        X"; break;
        case 54 : texte = "D: Hyrule kast�ly fel�"; break;
        case 55 : texte = "Sivatag templom**J�jj�n pr�b�lja ki f�rd�inket.*(A v�z nem ihat�)"; break;
        case 56 : texte = "Erd� templom**V�dd a f�kat, egy�l h�dot!"; break;
        case 57 : texte = "T� templom**F�rd� sapka k�telez�."; break;
        case 58 : texte = "J�g templom**A st�b arra eml�keztet, hogy a b�rt�n nem j�gp�lya."; break;
        case 59 : texte = "Tal�lkozt�l m�r a falu kov�cs�val?*�ll�t�lag nagyon j� kalandoz�k felszerel�s�nek feljav�t�s�ban. Sokan l�togatj�k meg."; break;
        case 60 : texte = "A templom a sivatag m�ly�n tal�lhat�, egy �si o�zisban."; break;
        case 61 : texte = "D: T�z f�ld*K: Kakariko falu"; break;
        case 62 : texte = "Hyrule kast�ly"; break;
        case 63 : texte = "K: Kakariko falu"; break;
        case 64 : texte = "NY: Tekn�s szikla*K: Hylia t�"; break;
        case 65 : texte = "Rejtett templom**Itt pihen a Gonosz Bane kardja, a Mesterkard."; break;
        case 66 : texte = "�: K�s�rtetj�rta temet� fel�"; break;
        case 67 : texte = "Megtal�ltad a B�rt�n t�rk�pet!*Nyomj START gombot a t�rk�p megtekint�s�hez."; break;
        case 68 : texte = "Megtal�ltad az Ir�nyt�t!*Megtal�lhatod vele a f�n�k�t �s a l�d�kat a terepen."; break;  
        case 69 : texte = "Megtal�ltad a F�n�k kulcsot!"; break;
        case 70 : texte = "Megtal�ltad a kis kulcsot!*S�t�lj egy ajt�hoz, hogy kinyitsd."; break;
        case 71 : texte = "Megtal�ltad a Keszty�t!*Haszn�ld t�rgyak emel�s�hez az X gombbal."; break;
        case 72 : 
            texte = "Tal�lt�l egy Var�zskrist�lyt!"; 
            tmp = 7-gpJeu->getJoueur()->nbCristaux();
            os << tmp;
            if (tmp==6 && !gpJeu->getJoueur()->getAvancement()) buffer = "Vajon mire haszn�lhat�...?";
            else if (tmp>2) buffer = "M�g "+os.str()+" darabot kell megtal�lni!";
            else if (tmp==2) buffer = "M�r csak kett�t kell megtal�lni!";
            else if (tmp==1) buffer = "Csak egy hi�nyzik!";
            else if (tmp==0) buffer = "Megvan az �sszes krist�ly, rohanj a v�rhoz �s mentsd meg Zeld�t!";
            break;
        case 80 : texte = "Megtal�ltad a Kamp�vet�t!*Haszn�ld az akad�lyokon �tjut�shoz."; break;
        case 81 : texte = "Megtal�ltad a L�mp�st!*Haszn�ld a dolgok felgy�jt�s�ra."; break;
        case 82 : texte = "Megtal�ltad az Uszonyt!*V�laszd ki a t�rgy men�ben hogy �ssz a v�zben."; break;
        case 83 : texte = "Megtal�ltad a M�gikus Kalap�csot!*Haszn�ld az akad�lyok sz�tver�s�re."; break;
        case 84 : texte = "Megtal�ltad a T�z P�lc�j�t!*Mostant�l k�pes vagy er�teljes l�ngokat kil�ni."; break;
        case 85 : texte = "Megtal�ltad a J�g P�lc�j�t!**Haszn�ld a t�volr�l fagyaszt�shoz."; break;
        case 86 : texte = "Megtal�ltad a Mesterkardot!*M�g Ganon sem tud ellen�llni az erej�nek... elm�letben!"; break;
        case 87 : texte = "K�sz�n�m, hogy megmentett�l, Link.***Tal�ljuk meg Ganont gyorsan; vissza kell szerezn�nk a Hatalomh�rmass�got!"; break;
        case 89 : texte = "A tr�nterem h�ts� r�sz�n l�v� titkos j�rat Ganonhoz vezet. Siess!"; break;
        case 90 : texte = "Nagyon k�zel vagyunk, k�vess!"; break;
        case 91 : texte = "Att�l tartok, hogy a jelenlegi fegyvereiddel nem tudod elpuszt�tani Ganont...*Menj �s besz�lj Kakariko falu f�n�k�vel, biztos vagyok benne, hogy kital�l egy megold�st."; break;
        case 92 : texte = "Ganon �pp az ajt� m�g�tt van. Meggy�gy�tom a sebeidet."; break;
        case 93 : texte = "Ganon m�g itt van valahol a kast�lyban."; break;
        case 94 : texte = "V�rnod kell Zelda hercegn�re!"; break;
        case 95 : texte = "Nincs az az �rz�sed, hogy valakit esetleg v�letlen�l elfelejtett�l?"; break;
        case 96 : texte = "Zelda v�r r�d!"; break;
        case 97 : texte = "Megtal�ltad a Hatalomh�rmass�got!"; break;
        case 98 : texte = "Megtal�ltad Mudora K�nyv�t!**Mostant�l �rteni fogod az �si Hylian nyelvet!"; break;
        case 99 : texte = "Gratul�lok, hogy megtal�lt�l, Link. Jutalmul neked adom Din med�lj�t. Megn�veli a v�delmedet 1 ponttal."; break;
        case 100 : texte = "Gratul�lok, hogy megtal�lt�l, Link. Jutalmul neked adom Nayru med�lj�t. Megn�veli a v�delmedet 2 ponttal."; break;
        case 101 : texte = "..."; break;
        case 102 : texte = "Szerezt�l egy m�gikus med�lt!**A v�delmed n�vekedett!"; break;
        case 103 : texte = "Gratul�lok, hogy megtal�lt�l, Link. Jutalmul megdupl�zom a kapacit�s�t a m�gia m�r�dnek!"; break;
        case 104 : texte = "A m�gia m�r�d megdupl�z�dott!"; break;
        case 105 : texte = "Gyere vissza, ha van egy �res �veged, �s akkor eladok neked egy v�r�s italt, ami helyre�ll�tja az �leter�d."; break;
        case 106 : texte = "Egy v�r�s ital 60 r�pi��rt. �rdekel?*             IGEN ?            nem  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=105; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<60) idsuiv=29;
            else idsuiv=108; break;
        case 107 : texte = "Egy v�r�s ital 60 r�pi��rt. �rdekel?*             igen              NEM ?"; break;
        case 108 : texte = "K�sz�n�m, itt az italod.";break;
        case 109 : texte = "Van egy v�r�s italod!*Idd meg az �leter�d vissza�ll�t�s�hoz."; break;
        case 110 : texte = "Van egy z�ld italod!*Idd meg a m�gia m�r�d vissza�ll�t�s�hoz."; break;
        case 111 : texte = "Van egy k�k italod!*Idd meg az �leter�d �s a m�gia m�r�d vissza�ll�t�s�hoz."; break;
        case 112 : texte = "Hello, mit szeretn�l inni?"; break;
        case 113 : texte = "-Hukk!- A t�nd�rek �ll�t�lag feljav�tott t�rgyakat adnak... -Hukk!- ...a kalandoz�knak akik megtal�lj�k �ket... -Hukk!!!-"; break;
		case 114 : texte = "Egy sz�v 10 r�pi��rt. �rdekel?**             IGEN ?            nem  "; 
            if (gpJeu->getJoueur()->getVie()+gpJeu->getJoueur()->getBoostVie()
            == gpJeu->getJoueur()->getVieMax()) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29;
            else idsuiv=129; break;
        case 115 : texte = "Egy sz�v 10 r�pi��rt. �rdekel?**             igen              NEM ?"; break;
        case 116 : texte = "Egy kev�ske m�gia 20 r�pi��rt. �rdekel?**             IGEN ?            nem  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<20) idsuiv=29;
            else idsuiv=129; break;
        case 117 : texte = "Egy kev�ske m�gia 20 r�pi��rt. �rdekel?**             igen              NEM ?"; break;
        case 118 : texte = "Egy kis m�gia 30 r�pi��rt. �rdekel?**             IGEN ?            nem  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 119 : texte = "Egy kis m�gia 30 r�pi��rt. �rdekel?**             igen              NEM ?"; break;
        case 120 : texte = "5 ny�l 30 r�pi��rt. �rdekel?**             IGEN ?            nem  "; 
            if (gpJeu->getJoueur()->getFleche() == gpJeu->getJoueur()->getFlecheMax() 
            || !gpJeu->getJoueur()->hasObjet(O_ARC)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 121 : texte = "5 ny�l 30 r�pi��rt. �rdekel?**             igen              NEM ?"; break;
        case 122 : texte = "Egy bomba 30 r�pi��rt. �rdekel?**             IGEN ?            nem  "; 
            if (gpJeu->getJoueur()->getBombe() == gpJeu->getJoueur()->getBombeMax() 
            || !gpJeu->getJoueur()->hasObjet(O_SAC_BOMBES)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 123 : texte = "Egy bomba 30 r�pi��rt. �rdekel?**             igen              NEM ?"; break;
        case 124 : texte = "Egy �j 1000 r�pi��rt. �rdekel?**             IGEN ?            nem  "; 
            idsuiv=29; break;
        case 125 : texte = "Egy �j 1000 r�pi��rt. �rdekel?**             igen              NEM ?"; break;
        case 126 : texte = "Egy �j 50 r�pi��rt. �rdekel?**             IGEN ?            nem  "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<50) idsuiv=29;
            else idsuiv=129; break;
        case 127 : texte = "Egy �j 50 r�pi��rt. �rdekel?**             igen              NEM ?"; break;
        case 128 : texte = "Nincs sz�ks�ged �pp most erre."; break;
        case 129 : texte = "K�sz�n�m."; break;
        case 130 : texte = "Megszerezted az �jat!*Haszn�ld t�voli c�lpontokra l�v�sre."; break;
        case 131 : texte = "V�lassz, amit szeretn�l."; break;
        case 132 : texte = "Mi?*A f�n�k k�ldet�s�n dolgozol?*Ok�, akkor kedvezm�nyt adok az �j �r�b�l"; break;
        case 133 : texte = "Hell� Link, �n vagyok a f�n�ke ennek a falunak. V�rtuk m�r a j�veteled."; idsuiv=134; break;
        case 134 : texte = "Ma reggel �ta sz�rnyek lepik be Hyrule vid�k�t. Pr�b�ltam besz�lni Zeld�val, de ahogy l�thattad m�r, egy er�s var�zslat elz�rja az utat a kast�lyba."; idsuiv=136; break;
        case 136 : texte = "Azt mondod Ganon felel�s mindez�rt? Ellopta a Hatalomh�rmass�got �s fogva tartja Zelda hercegn�t?"; idsuiv=137; break;
        case 137 : texte = "Mmmm... A helyzet rosszabb, mint gondoltam..."; idsuiv=138; break;
        case 138 : texte = "Gyorsan kell cselekedn�nk. �jra szembe kell sz�llnod Ganonnal!"; idsuiv=139; break;
        case 139 : texte = "Hogyan jutunk be a kast�lyba? Van egy �tletem..."; idsuiv=140; break;
        case 140 : texte = "Mint tudod, a 7 b�lcs hatalm�t Aghanim 7 krist�lyba z�rta, mikor megpr�b�lta megnyitni az utat a S�t�t Vil�g fel�, ahol Ganon tart�zkodott."; idsuiv=141; break;
        case 141 : texte = "Annak ellen�re, hogy a 7 b�lcs lesz�rmazottait felt�masztottad, miut�n legy�zted Ganont �s megtal�ltad a Hatalomh�rmass�got, ezek a krist�lyok megtartott�k erej�ket."; idsuiv=142; break;
        case 142 : texte = "7 templom m�ly�n rejtett�k el �ket. Gy�jtsd �ssze mind �s meg fogod tudni t�rni Ganon var�zslat�t."; idsuiv=143; break;
        case 143 : texte = "Ez azonban nem lesz k�nny�. Ganon biztosan a legjobb csapatait k�ldi a krist�lyok v�delm�re."; idsuiv=144; break;
        case 144 : texte = "Egy utols� dolog. A jelenlegi felszerel�seddel nem fogsz t�l messzire jutni. Menj �s tal�lkozz a fegyverkeresked�vel, �s mondd neki, hogy �n k�ldtelek. Val�sz�n�leg felaj�nl egy gesztust."; break;
        case 145 : texte = "Menj �s tal�lkozz a fegyverkeresked�vel, �s mondd neki, hogy �n k�ldtelek. Val�sz�n�leg felaj�nl egy gesztust."; break;
        case 146 : texte = "�ssze kell gy�jtened a 7 krist�lyt, hogy legyen es�lyed megmenteni Zeld�t and Hyrule-t."; break;
        case 147 : texte = "Megtal�ltad a 7 krist�lyt? Ir�ny a kast�ly! El�sz�r meg kell mentened a hercegn�t. � azt�n jobban fogja tudni n�lam, hogyan mentheted meg Hyrule-t."; break;
        case 148 : texte = "A fegyvereid semmit sem �rnek Ganon ellen? Meg kell tal�lnod a Mesterkardot. �ll�t�lag egy elrejtett templomban rejt�zik.*A Gonosz Bane Kardj�hoz vezet� �t �tmegy egy sz�rnyek lakta falun...*Csod�lkozn�k ha ilyen falu l�tezne."; break;
        case 150 : texte = "Egy�bk�nt att�l tartok, a jelenlegi felszerel�seddel alkalmatlan arra, hogy el�rd ezt a templomot. Tal�lkoznod kellene Gerudo falu kov�cs�val."; break;
        case 151 : texte = "Itt az ideje szembe sz�llni Ganonnal �s visszavenni a Hatalomh�rmass�got!"; break;
        case 152 : texte = "H�! Fizetned kell, hogy kinyithasd a l�daim egyik�t!"; break;
        case 153 : texte = "A l�d�k egyike tartalmaz egy sz�vdarabot. Szeretn�d megpr�b�lni 10 r�pi��rt?*Csak egy l�d�t nyithatsz ki, rendben?                        IGEN ?            nem "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29; break;
        case 154 : texte = "A l�d�k egyike tartalmaz egy sz�vdarabot. Szeretn�d megpr�b�lni 10 r�pi��rt?*Csak egy l�d�t nyithatsz ki, rendben?                        igen              NEM ?"; break;
        case 155 : texte = "V�lassz egy l�d�t."; break;
        case 156 : texte = "M�r nincs t�bb d�jam amit felaj�nlhatn�k nyerem�nynek, sajn�lom."; break;
        case 157 : texte = "Vesztett�l! A l�da �res. Pr�b�ld �jra!"; break;
        case 158 : texte = "Hell�! Ha a kov�csot keresed, � egy kicsit tov�bb el�re lakik."; break;
        case 159 : texte = "Hell� Link, �n vagyok ennek a falunak a f�n�ke.*�rdemes megl�togatnod a kov�csot �s megmutatnod neki a felszerel�st, amit fejleszteni szeretn�l.";
            buffer = "Hallottam a k�ldet�sedr�l �s elrendeztem mindent vele.*Minden ingyen lesz sz�modra."; break;
        case 160 : texte = "Nincs sz�ks�ged arra, hogy ezt az italt most megidd."; break;
        case 161 : texte = "Egy z�ld ital 40 r�pi��rt. �rdekel?**             IGEN ?            nem  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=163; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<40) idsuiv=29;
            else idsuiv=108; break;
        case 162 : texte = "Egy z�ld ital 40 r�pi��rt. �rdekel?**             igen              NEM ?"; break;
        case 163 : texte = "Gyere vissza, ha van egy �res �veged, �s akkor eladok neked egy z�ld italt, ami helyre�ll�ttja a m�gia m�r�d."; break;
        case 164 : texte = "Gyere vissza k�s�bb. Tele vagyok megrendel�ssel!"; break;
        case 165 : texte = "Tehetek �rted valamit?";
            if (gpJeu->getJoueur()->getEpee()==1) {id=166; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_GANTS)==1 && gpJeu->getJoueur()->getObjet()==8) {
                id=169; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_ARC)==2 && gpJeu->getJoueur()->getObjet()==0 
            && gpJeu->getJoueur()->nbCristaux()==7) {
                id=172; chercheText();break;}
            break;
        case 166 : texte = "Szeretn�d, hogy megedzem a kardod?**             IGEN ?            nem  "; break;
        case 167 : texte = "Szeretn�d, hogy megedzem a kardod??**             igen              NEM ?"; break;
        case 168 : texte = "A kardod ereje h�romszoros �s most m�r m�gikus sugarakat is l�hetsz. Annyira j�!*"; break;
        case 169 : texte = "Szeretn�d, hogy feljav�tsam a keszty�d?**             IGEN ?            nem  "; break;
        case 170 : texte = "Szeretn�d, hogy feljav�tsam a keszty�d?**             igen              NEM ?"; break;
        case 171 : texte = "A keszty�ben l�v� er� most m�r seg�t felemelni a neh�z szikl�kat!"; break;
        case 172 : texte = "Szeretn�d, hogy feljav�tsam az �jad?**             IGEN ?            nem  "; break;
        case 173 : texte = "Szeretn�d, hogy feljav�tsam az �jad?**             igen              NEM ?"; break;
        case 174 : texte = "Az �jad most m�r a kataklizmikus er� ez�st nyilait l�vi!"; break;
        case 175 : texte = "Gyere vissza, ha van egy �res �veged, �s akkor eladok neked egy k�k italt, ami helyre�ll�ttja az �leter�d �s a m�gia m�r�d."; break;
        case 176 : texte = "Egy k�k ital 160 r�pi��rt. �rdekel?**             IGEN ?            nem  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=175; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<160) idsuiv=29;
            else idsuiv=108; break;
        case 177 : texte = "Egy k�k ital 160 r�pi��rt. �rdekel?**             igen              NEM ?"; break;
        case 178 : texte = "A falunk az�rt �p�lt itt, hogy megakad�lyozza a felel�tlen kalandorok eljut�s�t a templomba. Nem engedek ak�rkit �t."; break;
        case 179 : texte = "Mmmm... m�r tal�lt�l 4 kritst�lyt?*Be kell valljam, leny�g�z�l...";
            buffer = "Rendben, �tmehetsz a temet�n, de csak a saj�t felel�s�gedre."; break;
        case 181 : texte = "Besz�lj az �rrel �szakra a falut�l. �t fog engedni."; break;
        case 182 : texte = "L�tom m�g �letben vagy...*Meglep�."; break;
        case 183 : texte = "A S�t�t templom a legend�s t�rgyhoz vezet� �t kiindul�pontja. Ez a falu csak az�rt l�tezik, hogy elt�ntor�tsa a kalandorokat a megk�zel�t�s�t�l."; break;
        case 184 : texte = "Teh�t megtal�ltad a Kardot?*De... ne gondold, hogy a ti�d.";
            buffer = "A Mesterkard a Hatalomh�rmass�g mellett Hyrule leg�rt�kesebb �r�ks�ge. Amint k�ldet�sed befejez�dik, vissza kell hoznod a szent�ly�be."; break;
        case 186 : texte = "A falu �sszes lak�ja szellem, aki v�laszolt Zelda hercegn� h�v�s�ra."; break;
        case 187 : texte = "Amikor visszahoztad a b�k�t Hyrule-ba, �s egyes�tetted a F�nyvil�got az Aranyf�lddel, Zelda titokban arra k�rte az �nk�ntes szellemeket, hogy hozz�k l�tre ezt a falut, amely elz�rva tart";
            buffer = "egy nagyon nagy �rt�k� t�rgyat."; break;
        
        case 189 : texte = "�dv�z�llek Link!*Engedd meg, hogy elmagyar�zzam mit csin�lok �n itt."; idsuiv=190; break;
        case 190 : texte = "Bizony�ra �szrevetted, hogy sz�rnyek jelentek meg Hyrule vid�k�n. Ez az els� alkalom, hogy sz�rnyeket l�tunk, mi�ta legy�zted Ganont."; idsuiv=191; break;
        case 191 : texte = "�gy d�nt�ttem list�zom mindegyiket."; idsuiv=192; break;
        case 192 : texte = "Sajnos, t�ls�gosan f�lek, hogy tal�lkozzak vel�k, �gy a seg�ts�gedre van sz�ks�gem."; idsuiv=193; break;
        case 193 : texte = "Minden fajta sz�rnnyel kell harcolnod �s ut�na hozz�m j�nni jelenteni."; idsuiv=194; break;
        case 194 : texte = "Minden alkalommal, amikor 7 �j fajta ellens�get elpuszt�tott�l, kapsz egy sz�vdarabot."; idsuiv=195; break;
        case 195 : texte = "Ha szeretn�d megn�zni, milyen ellens�get �lt�l m�r nyomj L �s B gombokat."; break;
        
        
        case 196 : 
            if (gpJeu->getJoueur()->getCoeur(43)) {
                if (gpJeu->getJoueur()->nbEnnemis() >= 46) {id=205; chercheText();return;}
                else {id=204; chercheText();return;}
            }
            for (int i = 38; i < 44; i++) 
                if (!gpJeu->getJoueur()->getCoeur(i) 
                && (gpJeu->getJoueur()->nbEnnemis()/7)+37>=i) {
                    id=203; chercheText();return;
                }
            tmp = 7-(gpJeu->getJoueur()->nbEnnemis()%7);
            os << tmp;
            if (tmp>1) texte = "Sz�ks�ged van m�g "+os.str()+" k�l�nb�z� ellenf�lre a k�vetkez� jutalomhoz.";
            else texte = "M�r csak egy ellens�gre van sz�ks�g a k�vetkez� jutalomhoz!";
            break;
        case 203 : texte = "Fogadd ezt az aj�nd�kot k�sz�netk�nt a projektemhez val� hozz�j�rul�s�rt:"; break;
        case 204 : texte = "Sajn�lom, de t�bb� m�r nincs semmim sz�modra."; break;
        case 205 : texte = "El sem hiszem, siker�lt minden fajta ellenfelet legy�zn�d!*Gratul�lok, Link!"; break;
        
        case 206 : texte = "                    1.szint:**                   Erd� templom"; break;
        case 207 : texte = "                    2.szint:**                   V�z templom"; break;
        case 208 : texte = "                    3.szint:**                  Hegyi templom"; break;
        case 209 : texte = "                    4.szint:**                 Sivatag templom"; break;
        case 210 : texte = "                    5.szint:**                   S�t�t templom"; break;
        case 211 : texte = "                    6.szint:**                   T�z templom"; break;
        case 212 : texte = "                    7.szint:**                   J�g templom"; break;
        case 213 : texte = "                    ?.szint:**                 Rejtett templom"; break;
        case 214 : texte = "               Utols� szint:**                  Hyrule kast�ly"; break;
        
        case 215 :texte = "                  M�r elf�radt?                  ?                 FOLYTAT�S                ?                   Ment �s kil�p                               Kil�p�s ment�s n�lk�l          "; break;
        case 216 :texte = "                  M�r elf�radt?                                    Folytat�s                    ?               MENT �S KIL�P              ?                Kil�p�s ment�s n�lk�l          "; break;
        case 217 :texte = "                  M�r elf�radt?                                    Folytat�s                                    Ment �s kil�p                  ?            KIL�P�S MENT�S N�LK�L         ?"; break;
        
        case 223 : texte = "Abban a pillanatban, amikor Link meg�rintette a Hatalomh�rmass�got, a sz�rnyek elt�ntek, �s visszat�rt a b�ke. ** Zelda hercegn� azt�n egy nagyszer� d�nt�st hozott: meg�rintette a Hatalomh�rmass�got �s megfogalmazta k�v�ns�g�t. ** A Hatalomh�rmass�g mindig is csak a Kir�lys�g bajainak forr�sa volt. El�bb vagy ut�bb �jra megtal�ln� egy m�sik gonosz l�ny.** Amikor Zelda hercegn� meg�rintette az erekly�t, az elt�nt Hyrule-b�l ... �r�kre.";
            buffer = "Ett�l a napt�l kezdve Hyrule n�pe b�k�ben �lt, nem f�lve az �j katasztr�f�kt�l.** �gy esett meg Zelda legend�ja, a Hatalomh�rmass�gr�l �s az Aranyf�ldr�l.** �ll�t�lag a Mesterkard nyugodtan pihen valahol, mint Link k�ldet�s�nek utols� mement�ja."; break;
        case 224 : texte = "Gratul�lok, hogy megtal�lt�l, Link. Jutalmul neked adom Farore med�lj�t. Megn�veli a v�delmedet 1 ponttal."; break;
        case 225 : texte = "Szeretn� menteni a j�t�kot?**                   ? IGEN ?*                      nem  "; break;
        case 226 : texte = "Szeretn� menteni a j�t�kot?**                     igen  *                    ? NEM ?"; break;
        case 227 : texte = "J�t�k mentve."; break;
        
        case 228 : texte = "A Hyrule Kir�lys�gban b�ke honol, mi�ta Link, Hyrule utols� lovagja legy�zte a gonosz Ganont, �s visszaszerezte t�le a dr�ga Hatalomh�rmass�got."; idsuiv = 229; break;
        case 229 : texte = "Senki sem tudja, mi volt Link k�v�ns�ga a Hatalomh�rmass�ghoz, de a F�ny �s a S�t�t vil�g egyes�t�se �s a 7 b�lcs ember lesz�rmazottainak felt�maszt�sa lett az eredm�nye."; idsuiv = 230; break;
        case 230 : texte = "Link ezut�n �tadta a Hatalomh�rmass�got �s a Mesterkardot Zelda hercegn�nek, �s az emberek kezdt�k elhinni, hogy ez a b�ke tart�s lesz. * De az emberek t�vedtek..."; idsuiv=231; break;
        case 231 : texte = "Sajnos Link k�v�ns�g�nak negat�v hat�sai is lettek. Ganon �s csatl�sai felt�madtak, �s t�mad�sra k�sz�ltek."; idsuiv=232; break;
        case 232 : texte = "Link valahol a Hyrule erd�ben alszik an�lk�l, hogy sejten�, Ganon m�ris t�mad�sba lend�lt, am�g egy"; 
            buffer="ismer�s hang nem sz�lt hozz� �lm�ban..."; break;
        case 233 : texte = "Seg�ts!*Seg�ts!*�n vagyok! Zelda!*Telepatikusan sz�lok hozz�d."; idsuiv = 234; break;
        case 234 : texte = "Rab vagyok a v�r b�rt�n�ben!*Sz�ks�gem van a seg�ts�gedre!*Ganon visszat�rt, �s biztosan megtal�lta m�r a Hatalomh�rmass�got..."; idsuiv=235; break;
        case 235 : texte = "Gyere gyorsan a kast�lyhoz, Link! Te vagy az egyetlen rem�nyem..."; break;
        case 236 : texte = "S�G�: Nyomj L �s Y gombott a s�g� men� megtekint�s�hez."; break;
    }
break; // Hungarian



//////////HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHUUUUUUUUUUUUUUUUUUUUUUUUUUUUU



default:	
    switch (id) {
        case 1  : texte = "You found a shield!**Your defense increases by one point!"; break;
        case 2  : texte = "You found a sword!**You can now fight monsters with the B .*Hold B to charge a spin attack!"; break;
        case 3  : 
            tmp = 4-(gpJeu->getJoueur()->nbQuarts()%4);
            os << tmp;
            texte = "You found a piece of heart!!!";
            if (tmp<4) buffer = "You need "+os.str()+" more for a new heart container.";
            else buffer = "Your heart level increased!";
            break;
        case 11 : texte = "N: Link's Home*W: Hyrule Field*E: Forest Temple"; break;
        case 12 : texte = "Mountain Temple**Not for cardiacs, scaredy-cats, and the generally faint of heart."; break;
        case 13 : texte = "W: Desert entrance*N: Mountain Temple"; break;
        case 14 : texte = "N: Mountain Temple*S: Hyrule Field"; break;
        case 15 : texte = "N: Death Mountain"; break;
        case 16 : texte = "E: Forest Entrance"; break;
        case 17 : texte = "S: Lake Hylia*E: Haunted Graveyard"; break;
        case 18 : texte = "S: To Kakariko Village"; break;
        case 19 : texte = "N: Kakariko Village"; break;
        case 20 : texte = "N: Hyrule Field"; break;
        case 21 : texte = "W: Fire Land"; break;
        case 22 : texte = "E: Shadow Village*- Not for the living -"; break;
        case 23 : texte = "Dark Temple**If you are a ghost, looking for a job, you'd better come here to hang out with us."; break;
        case 24 : texte = "N: Shadow Village*W: Lake Hylia"; break;
        case 25 : texte = "N: Haunted Graveyard**No entry"; break;
        case 26 : texte = "Shadow Village"; break;
        case 27 : texte = "I am selling a bottle for 100 rupees, are you interested?*              YES ?            no  "; 
            if ((gpJeu->getJoueur()->hasBouteille(0) && gpJeu->getZone()==8)
            || (gpJeu->getJoueur()->hasBouteille(1) && gpJeu->getZone()==5)
            || (gpJeu->getJoueur()->hasBouteille(2) && gpJeu->getZone()==6)) {id=32; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<100) idsuiv=29;
            else idsuiv=30;
            break;
        case 28 : texte = "I am selling a bottle for 100 rupees, are you interested?*              yes             NO ?"; idsuiv=31; break;
        case 29 : texte = "Sorry, you don't have enough rupees"; break;
        case 30 : texte = "Thank you, here is your bottle."; break;
        case 31 : texte = "Come again if you change your mind."; break;
        case 32 : texte = "Sorry, that was my only bottle."; break;
        case 33 : texte = "You find an empty bottle!**It will help you to store potions."; break;
        case 35 : texte = "The inhabitants of that village have a dialect out of the ordinary. I don't understand anything..."; break;
        case 36 : texte = "@+@+@+@+@+@+@@@+*@=++=@=+@=+@=+=@*+@+@+@+=+="; break;
        case 37 : texte = "Wangle chief's permit if you really want to pass!"; break;
        case 38 : texte = "The chief allowed you to pass? Grrrr... So move along!"; break;
        case 39 : texte = "Get out of my way!"; break;
        case 40 : texte = "We don't often have visitors around here."; break;
        case 41 : texte = "Local monsters don't fear many things. Fortunately, they only attack humans."; break;
        case 42 : texte = "Really?*You understand what I'm saying?"; break;
        case 43 : texte = "N: Desert and Gerudo Village"; break;
        case 44 : texte = "S: Lake Hylia*W: Hyrule Castle"; break;
        case 45 : texte = "Kakariko Village"; break;
        case 46 : texte = "W: Hyrule Castle"; break;
        case 47 : texte = "What a good day!"; break;
        case 48 : texte = "Why did I accept to take care of that rubbish?*I loathe hens!"; break;
        case 49 : texte = "You can find a lot of things in this village's shop."; break;
        case 50 : texte = "S: Kakariko Village*W: Desert*E: Death Mountain"; break;
        case 51 : texte = "Gerudo Village"; break;
        case 52 : texte = "Lost in the desert?*You are here:*                        X"; break;
        case 54 : texte = "S: To Hyrule Castle"; break;
        case 55 : texte = "Desert Temple**Come to try our baths.*(The water is not for drinking)"; break;
        case 56 : texte = "Forest Temple**Save the trees, eat beaver!"; break;
        case 57 : texte = "Lake Temple**Bathing cap mandatory."; break;
        case 58 : texte = "Ice Temple**The staff would like to remind you that a dungeon is not a ice rink."; break;
        case 59 : texte = "Did you see the blacksmith of this village?*He is said to be very gifted in the way of improving adventurers' equipment. A lot of people visit him."; break;
        case 60 : texte = "The Temple is in the deepest desert, in an ancient oasis."; break;
        case 61 : texte = "S: Fire Land*E: Kakariko Village"; break;
        case 62 : texte = "Hyrule Castle"; break;
        case 63 : texte = "E: Kakariko Village"; break;
        case 64 : texte = "W: Turtle Rock*E: Lake Hylia"; break;
        case 65 : texte = "Hidden Temple**Here rests the Sword of Evils Bane, the Master Sword."; break;
        case 66 : texte = "N: To the Haunted Graveyard"; break;
        case 67 : texte = "You found the Dungeon Map!*Press the START button to view the map."; break;
        case 68 : texte = "You found the Compass!*You can locate the boss and chests on the plan."; break;
        case 69 : texte = "You found the Boss Key!"; break;
        case 70 : texte = "You found a small key!*Walk up to a door to open it."; break;
        case 71 : texte = "You found the Gloves!*Use them to lift objects with the X button."; break;
        case 72 : 
            texte = "You found a Magic Crystal!"; 
            tmp = 7-gpJeu->getJoueur()->nbCristaux();
            os << tmp;
            if (tmp==6 && !gpJeu->getJoueur()->getAvancement()) buffer = "What could it be used for...?";
            else if (tmp>2) buffer = "There are "+os.str()+" left to find!";
            else if (tmp==2) buffer = "Only two left to find!";
            else if (tmp==1) buffer = "You are only missing one!";
            else if (tmp==0) buffer = "You have all the crystals, run to the castle and save Zelda!";
            break;
        case 80 : texte = "You found the Hookshot!*Use it to overcome obstacles."; break;
        case 81 : texte = "You found the Lantern!*Use it to set things on fire."; break;
        case 82 : texte = "You found the Flippers!*Select them in the item menu to swim in the water."; break;
        case 83 : texte = "You found the Magic Hammer!*Use it to squash obstacles."; break;
        case 84 : texte = "You found the Fire Rod!*From now on you are able to shoot out powerful flames."; break;
        case 85 : texte = "You found the Ice Rod!*Use it to freeze anything from a distance."; break;
        case 86 : texte = "You found the Master Sword!*Even Ganon could not stand up to its power... in theory!"; break;
        case 87 : texte = "Thank you for saving me, Link.***Let's find Ganon quickly; we have to reclaim the Triforce!"; break;
        case 89 : texte = "The secret passage at the back of the throne room leads to Ganon. Hurry up!"; break;
        case 90 : texte = "We are very near, follow me!"; break;
        case 91 : texte = "I'm afraid you are not able to defeat Ganon with your current weapons...*Go and speak to the chief of Kakariko Village, I am sure he will find a solution."; break;
        case 92 : texte = "Ganon is just behind that door. I will cure your wounds."; break;
        case 93 : texte = "Ganon is still somewhere in the castle."; break;
        case 94 : texte = "You should wait for Princess Zelda!"; break;
        case 95 : texte = "Don't you have the strange feeling that you are forgetting someone, by any chance?"; break;
        case 96 : texte = "Zelda is waiting for you!"; break;
        case 97 : texte = "You found the Triforce!"; break;
        case 98 : texte = "You found the Book of Mudora!**From now on, you understand the ancient Hylian language!"; break;
        case 99 : texte = "Congratulations for finding me, Link. As a reward, I give you Din's Pendant. It increases your defense by one point."; break;
        case 100 : texte = "Congratulations for finding me, Link. As a reward, I give you Nayru's Pendant. It increases your defense by two points."; break;
        case 101 : texte = "..."; break;
        case 102 : texte = "You obtain a magic pendant!**Your defense increased!"; break;
        case 103 : texte = "Congratulation for finding me, Link. As a reward, I will double the capacity of your magic meter!"; break;
        case 104 : texte = "Your magic meter has been doubled!"; break;
        case 105 : texte = "Come back when you have an empty bottle, and I will sell you a red potion which restores your health."; break;
        case 106 : texte = "A red potion for 60 rupees. Are you interested?*              YES ?            no  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=105; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<60) idsuiv=29;
            else idsuiv=108; break;
        case 107 : texte = "A red potion for 60 rupees. Are you interested?*              yes              NO ?"; break;
        case 108 : texte = "Thank you, here is your potion.";break;
        case 109 : texte = "You got a red potion!*Drink it to restore your health."; break;
        case 110 : texte = "You got a green potion!*Drink it to restore your magic meter."; break;
        case 111 : texte = "You got a blue potion!*Drink it to restore your health and magic meter."; break;
        case 112 : texte = "Hello, what would you like to drink?"; break;
        case 113 : texte = "-Hiccup!- A fairy is said to give enchanted objects... -Hiccup!- ...to the adventurers who would find her... -Hiccup!!!-"; break;
        case 114 : texte = "One heart for 10 rupees. Are you interested?**              YES ?            no  "; 
            if (gpJeu->getJoueur()->getVie()+gpJeu->getJoueur()->getBoostVie()
            == gpJeu->getJoueur()->getVieMax()) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29;
            else idsuiv=129; break;
        case 115 : texte = "One heart for 10 rupees. Are you interested?**              yes              NO ?"; break;
        case 116 : texte = "A little bit of magic for 20 rupees. Are you interested?**              YES ?            no  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<20) idsuiv=29;
            else idsuiv=129; break;
        case 117 : texte = "A little bit of magic for 20 rupees. Are you interested?**              yes              NO ?"; break;
        case 118 : texte = "Some magic for 30 rupees. Are you interested?**              YES ?            no  "; 
            if (gpJeu->getJoueur()->getMagie()+gpJeu->getJoueur()->getBoostMagie()
            == gpJeu->getJoueur()->getMagieMax() || !gpJeu->getJoueur()->hasObjet(O_LANTERNE)) {
                id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 119 : texte = "Some magic for 30 rupees. Are you interested?**              yes              NO ?"; break;
        case 120 : texte = "5 arrows for 30 rupees. Are you interested?**              YES ?            no  "; 
            if (gpJeu->getJoueur()->getFleche() == gpJeu->getJoueur()->getFlecheMax() 
            || !gpJeu->getJoueur()->hasObjet(O_ARC)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 121 : texte = "5 arrows for 30 rupees. Are you interested?**              yes              NO ?"; break;
        case 122 : texte = "One bomb for 30 rupees. Are you interested?**              YES ?            no  "; 
            if (gpJeu->getJoueur()->getBombe() == gpJeu->getJoueur()->getBombeMax() 
            || !gpJeu->getJoueur()->hasObjet(O_SAC_BOMBES)) {id=128; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<30) idsuiv=29;
            else idsuiv=129; break;
        case 123 : texte = "One bomb for 30 rupees. Are you interested?**              yes              NO ?"; break;
        case 124 : texte = "A bow for 1000 rupees. Are you interested?**              YES ?            no  "; 
            idsuiv=29; break;
        case 125 : texte = "A bow for 1000 rupees. Are you interested?**              yes              NO ?"; break;
        case 126 : texte = "A bow for 50 rupees. Are you interested?**              YES ?            no  "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<50) idsuiv=29;
            else idsuiv=129; break;
        case 127 : texte = "A bow for 50 rupees. Are you interested?**              yes              NO ?"; break;
        case 128 : texte = "You don't need this right now."; break;
        case 129 : texte = "Thank you."; break;
        case 130 : texte = "You got the bow!*Use it to shoot at distant targets."; break;
        case 131 : texte = "Pick what you want."; break;
        case 132 : texte = "What?*You are on a mission for the chief?*Okay, so I'm going to give you a discount on the bow"; break;
        case 133 : texte = "Hello Link, I am the chief of this village. I suspected you were coming."; idsuiv=134; break;
        case 134 : texte = "Since this morning, monsters stride along Hyrule. I tried to talk to Zelda about it, but as you've perhaps already seen, a powerful spell blocks the access to the castle."; idsuiv=136; break;
        case 136 : texte = "You say Ganon is responsible for all of this? He stole the Triforce and he holds Princess Zelda captive?"; idsuiv=137; break;
        case 137 : texte = "Mmmm... The situation is more serious than I thought..."; idsuiv=138; break;
        case 138 : texte = "We have to act very quickly. You must face Ganon again!"; idsuiv=139; break;
        case 139 : texte = "How do we enter the castle? I may have an idea..."; idsuiv=140; break;
        case 140 : texte = "As you know, the power of the 7 wise men was locked up in 7 crystals by Aghanim when he was trying to open up the path to the Dark World, where Ganon was."; idsuiv=141; break;
        case 141 : texte = "Yet, even if you raised the descendants of the 7 wise men from the dead after you defeated Ganon and found the Triforce, these crystals have kept their power."; idsuiv=142; break;
        case 142 : texte = "They have been hidden deep in the 7 temples. Gather them all, and you'll be able to get over Ganon's spell."; idsuiv=143; break;
        case 143 : texte = "That won't be easy, however. Ganon will surely send his best troops to protect these crystals."; idsuiv=144; break;
        case 144 : texte = "One last thing. You won't go very far with your current equipment. Go and see the arms dealer and tell him that you're coming on my behalf. He will probably make a gesture for you."; break;
        case 145 : texte = "Go and see the arms dealer and tell him that you're coming on my behalf. He will probably make a gesture for you."; break;
        case 146 : texte = "You have to gather the 7 crystals to have a chance at saving Zelda and Hyrule."; break;
        case 147 : texte = "You found the 7 crystals? Go to the castle! First, you have to save the princess. She will know better than I how to save Hyrule."; break;
        case 148 : texte = "Your weapons are null and void against Ganon? You have to find the Master Sword. It is said to have been concealed in a hidden temple.*The way leading to the Sword of Evils Bane is said to cross over a village populated by monsters...*I wonder if such a village exists."; break;
        case 150 : texte = "However, I'm afraid that your current equipment is inadequate for reaching this temple. You should go see the blacksmith of Gerudo village."; break;
        case 151 : texte = "It's about time to face Ganon and take the Triforce back!"; break;
        case 152 : texte = "Hey! You have to pay to open one of my chests!"; break;
        case 153 : texte = "One of these chests contains a piece of heart. Do you want to try for 10 rupees?*You will only be allowed to open one chest, ok?               YES ?            no  "; 
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<10) idsuiv=29; break;
        case 154 : texte = "One of these chests contains a piece of heart. Do you want to try for 10 rupees?*You will only be allowed to open one chest, ok?               yes              NO ?"; break;
        case 155 : texte = "Pick a chest."; break;
        case 156 : texte = "I don't have anymore prizes to bring into play, sorry."; break;
        case 157 : texte = "You lose! This chest is empty. Try again!"; break;
        case 158 : texte = "Hello! If you are looking for the blacksmith, he lives a little further ahead."; break;
        case 159 : texte = "Hello Link, I am the chief of this village.*You should go to see the blacksmith and show him what equipment you want him to improve.";
            buffer = "I have heard of your quest, so I have arranged everything with him.*All will be free for you."; break;
        case 160 : texte = "You don't need to drink this potion right now."; break;
        case 161 : texte = "A green potion for 40 rupees. Are you interested?*              YES ?            no  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=163; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<40) idsuiv=29;
            else idsuiv=108; break;
        case 162 : texte = "A green potion for 40 rupees. Are you interested?*              yes              NO ?"; break;
        case 163 : texte = "Come back when you have an empty bottle, and I will sell you a green potion which restores your magic meter."; break;
        case 164 : texte = "Come back later. I am overbooked!"; break;
        case 165 : texte = "May I do something for you?";
            if (gpJeu->getJoueur()->getEpee()==1) {id=166; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_GANTS)==1 && gpJeu->getJoueur()->getObjet()==8) {
                id=169; chercheText();break;}
            if (gpJeu->getJoueur()->hasObjet(O_ARC)==2 && gpJeu->getJoueur()->getObjet()==0 
            && gpJeu->getJoueur()->nbCristaux()==7) {
                id=172; chercheText();break;}
            break;
        case 166 : texte = "Do you want me to temper your sword?**              YES ?            no  "; break;
        case 167 : texte = "Do you want me to temper your sword?**              yes              NO ?"; break;
        case 168 : texte = "Your sword triples in power and you can now shoot magic beams. So good!*"; break;
        case 169 : texte = "Do you want me to upgrade your gloves?**              YES ?            no  "; break;
        case 170 : texte = "Do you want me to upgrade your gloves?**              yes              NO ?"; break;
        case 171 : texte = "The power of your gloves now helps you lift heavy rocks!"; break;
        case 172 : texte = "Do you want me to upgrade your bow?**              YES ?            no  "; break;
        case 173 : texte = "Do you want me to upgrade your bow?**              yes              NO ?"; break;
        case 174 : texte = "Your bow now shoots silver arrows of cataclysmic power!"; break;
        case 175 : texte = "Come back when you have an empty bottle, and I will sell you a blue potion which restores your health and your magic meter."; break;
        case 176 : texte = "A blue potion for 160 rupees. Are you interested?*              YES ?            no  "; 
            if (gpJeu->getJoueur()->hasBouteille(0)!=1
            && gpJeu->getJoueur()->hasBouteille(1)!=1
            && gpJeu->getJoueur()->hasBouteille(2)!=1) {id=175; chercheText();break;}
            if (gpJeu->getJoueur()->getRubis() + gpJeu->getJoueur()->getBoostRubis()<160) idsuiv=29;
            else idsuiv=108; break;
        case 177 : texte = "A blue potion for 160 rupees. Are you interested?*              yes              NO ?"; break;
        case 178 : texte = "Our village has been built here with the purpose of preventing careless adventurers from reaching the temple. I won't allow just anyone to pass."; break;
        case 179 : texte = "Mmmm... You already found 4 crystals?*I have got to admit, you impress me...";
            buffer = "All right, you are allowed to cross over the graveyard, at your own risk."; break;
        case 181 : texte = "Talk to the guard at the north of the village. He will let you pass."; break;
        case 182 : texte = "I see you're still alive...*Surprising."; break;
        case 183 : texte = "The dark temple is the starting point of the way leading to a legendary object. This village only exists to dissuade adventurers from approaching."; break;
        case 184 : texte = "So you found the Sword?*But... don't believe it is yours.";
            buffer = "The Master Sword is among the most treasured heritage of Hyrule along with the Triforce. You will have to bring it back to its sanctuary once your mission is completed."; break;
        case 186 : texte = "All the inhabitants of this village are spirits who answered to Princess Zelda's call."; break;
        case 187 : texte = "When you returned peace to Hyrule and reunified the Light World with the Golden Land, Zelda secretly asked volunteer spirits to create this village to block";
            buffer = "the access to a very high valued object."; break;
        
        case 189 : texte = "Welcome Link!*Let me explain to you what I am doing here."; idsuiv=190; break;
        case 190 : texte = "As you certainly have noticed, monsters appeared in Hyrule. It's the first time I can see monsters since your victory on Ganon."; idsuiv=191; break;
        case 191 : texte = "I have decided to list all of them."; idsuiv=192; break;
        case 192 : texte = "Unfortunately, I'm too fearful to meet them, so I need your help."; idsuiv=193; break;
        case 193 : texte = "You have to fight each kind of monster and come to give me your report."; idsuiv=194; break;
        case 194 : texte = "Each time you have defeated 7 new kinds of enemies, I will give you a piece of heart."; idsuiv=195; break;
        case 195 : texte = "If you want to see what enemies you've already defeated, press the L and B buttons."; break;
        
        
        case 196 : 
            if (gpJeu->getJoueur()->getCoeur(43)) {
                if (gpJeu->getJoueur()->nbEnnemis() >= 46) {id=205; chercheText();return;}
                else {id=204; chercheText();return;}
            }
            for (int i = 38; i < 44; i++) 
                if (!gpJeu->getJoueur()->getCoeur(i) 
                && (gpJeu->getJoueur()->nbEnnemis()/7)+37>=i) {
                    id=203; chercheText();return;
                }
            tmp = 7-(gpJeu->getJoueur()->nbEnnemis()%7);
            os << tmp;
            if (tmp>1) texte = "You need "+os.str()+" more different enemies before your next reward.";
            else texte = "You only need one more enemy before your next reward!";
            break;
        case 203 : texte = "Take this gift as a thank you for your contribution to my project:"; break;
        case 204 : texte = "I'm sorry, but I don't have anything for you anymore."; break;
        case 205 : texte = "I can't take it in, you succeeded in defeating all kinds of enemies!*Congratulations, Link!"; break;
        
        case 206 : texte = "                    Level 1:**                  Forest Temple"; break;
        case 207 : texte = "                    Level 2:**                  Water Temple"; break;
        case 208 : texte = "                    Level 3:**                 Mountain Temple"; break;
        case 209 : texte = "                    Level 4:**                  Desert Temple"; break;
        case 210 : texte = "                    Level 5:**                   Dark Temple"; break;
        case 211 : texte = "                    Level 6:**                   Fire Temple"; break;
        case 212 : texte = "                    Level 7:**                   Ice Temple"; break;
        case 213 : texte = "                    Level ?:**                  Hidden Temple"; break;
        case 214 : texte = "                  Last Level:**                 Hyrule Castle"; break;
        
        case 215 :texte = "                 Already tired?                  ?                 CONTINUE                 ?                   Save and quit                               Quit without saving            "; break;
        case 216 :texte = "                 Already tired?                                    Continue                     ?               SAVE AND QUIT              ?                Quit without saving            "; break;
        case 217 :texte = "                 Already tired?                                    Continue                                     Save and quit                  ?            QUIT WITHOUT SAVING           ?"; break;
        
        case 223 : texte = "At the exact same time Link touched the Triforce, the monsters disappeared,and peace returned.**Princess Zelda then made a great decision: she touched the Triforce and made her wish.**The Triforce had always been the origin of troubles in the Kingdom. Sooner or later, another evil creature would find it.**When Princess Zelda touched the relic, it disappeared from Hyrule... forever.";
            buffer = "From this day, the people of Hyrule have lived in peace, without fear of new disasters.**Thus the Legend of Zelda, of the Triforce, and of the Golden Land, is achieved.**The Master Sword is said to rest safely somewhere and to be the last heirloom of Link's quest."; break;
        case 224 : texte = "Congratulations for finding me, Link. As a reward, I give you Farore's Pendant. It increases your defense by one point."; break;
        case 225 : texte = "Do you want to save the game?**                    ? YES ?*                      no  "; break;
        case 226 : texte = "Do you want to save the game?**                      yes  *                    ? NO ?"; break;
        case 227 : texte = "Game saved."; break;
        
        case 228 : texte = "The Kingdom of Hyrule has been in peace since Link, the last knight of Hyrule, had defeated the malicious Ganon and reclaimed the precious Triforce from him."; idsuiv = 229; break;
        case 229 : texte = "Nobody knows what Link's wish to the Triforce was, but it had the effect of reunifying the Light and Dark World, and resurrecting the 7 wise men's descendants."; idsuiv = 230; break;
        case 230 : texte = "Link then handed the Triforce and the Master Sword over to Princess Zelda, and people started believing that peace would last.*But the people were wrong..."; idsuiv=231; break;
        case 231 : texte = "Unfortunately, Link's wish also had negative effects. Ganon and his henchmen were resurrected and got ready to attack."; idsuiv=232; break;
        case 232 : texte = "Somewhere in Hyrule Forest, Link is sleeping without suspecting that Ganon has already moved into the attack, until a"; 
            buffer="well-known voice talked to him in his sleep..."; break;
        case 233 : texte = "Help me!*Help me!*It's me! Zelda!*I'm talking to you via telepathy."; idsuiv = 234; break;
        case 234 : texte = "I am a prisoner in the dungeon of the castle!*I need your help!*Ganon is back, and he surely has already found the Triforce..."; idsuiv=235; break;
        case 235 : texte = "Come, quickly, to the castle, Link! You are my only hope..."; break;
        case 236 : texte = "HELP: Press L and Y to view the help menu."; break;
    }
	break; // default language : English
}
    
    
}

void Texte::affiche(SDL_Surface* gpScreen, std::string s, int a, int b) {
    for (int i = 0; i < (int)s.length(); i++) {
        afficheLettre(gpScreen, s.at(i),a,b);
        a+=6;
    }
}

void Texte::draw(SDL_Surface* gpScreen) {
    
    if (cadre) drawCadre(gpScreen);
	
	std::string comptexte;
	
switch(getLanguage()) {

case 2: // French
	comptexte = "Tu as trouv� un quart de coeur !!!";
break;

case 3: // German
	comptexte = "Du hast ein Herzfragment gefunden!!!";
break;

case 4: // Italian
	comptexte = "Hai trovato una parte di cuore !!!";
break;

case 5: // Spanish
	comptexte = "Has encontrado un cuarto de coraz�n !!!";
break;

case 6: // Hungarian
	comptexte = "Tal�lt�l egy sz�vdarabot!!!";
break;

default:
	comptexte = "You found a piece of heart!!!";
break;	
}    
//    if (id==3 && texte == "You find a piece of heart!!!") {
    if (id==3 && texte == comptexte) {
        SDL_Rect src; SDL_Rect dst;
        src.x=16*(gpJeu->getJoueur()->nbQuarts()%4);
        if(src.x==0)src.x=16*4;
        src.y=0; src.w=16; src.h=16; dst.x=160-8; dst.y=120-8+16*5;
        SDL_BlitSurface(imageCoeur, &src, gpScreen, &dst);
    }
    
    int a = x+8; int b = y+8;
    for (int i = 0; i < av; i++) {
        afficheLettre(gpScreen, texte.at(i),a,b);
        a+=6;
        if (a > x+w-16) {a=x+8; b+=16;}
    }
    
    if(SDL_GetTicks() > lastAnimTime + vitesse && def && av < (int)texte.length()) {
        lastAnimTime = SDL_GetTicks();
        do av++;
        while (av < (int)texte.length() && texte.at(av-1) == ' ');
        if (texte.at(av-1) != ' ') gpJeu->getAudio()->playSound(0,1);
    }
}

bool Texte::isFinished() {return (av==(int)texte.length());}

int Texte::getId() {return id;}

void Texte::changeId(int i) {
    id=i; idsuiv=0; buffer="";
    chercheText();
    decoupeText();
    if (av>(int)texte.length()) av=(int)texte.length();
}

void Texte::drawCadre(SDL_Surface* gpScreen) {
    SDL_Rect src;
    SDL_Rect dst;
    
    src.w=8; src.h=8; src.x = 103; src.y = 100; dst.x = x; dst.y = y;
    SDL_BlitSurface(imageFont, &src, gpScreen, &dst);
    
    src.x = 112;
    for (int i = 8; i < w-8; i+=16) {
        dst.x = x+i; src.w=16;
        while (dst.x + src.w > x+w && src.w>0) src.w--;
        if (src.w>0) SDL_BlitSurface(imageFont, &src, gpScreen, &dst);
    }
    
    src.w=8; src.x = 129; dst.x = x+w-8;
    SDL_BlitSurface(imageFont, &src, gpScreen, &dst);
    
    src.y = 109; src.w=8;
    for (int j = 8; j < h-8; j+=16) {
        dst.y = y + j;
        src.x = 103; dst.x = x; src.h=16;
        while (dst.y + src.h > y+h && src.h>0) src.h--;
        if (src.h>0) SDL_BlitSurface(imageFont, &src, gpScreen, &dst);
    
        src.x = 129; dst.x = x+w-8;
        if (src.h>0)SDL_BlitSurface(imageFont, &src, gpScreen, &dst);
    }
    
    src.h=8; src.x = 103; src.y = 126; dst.x = x; dst.y = y+h-8;
    SDL_BlitSurface(imageFont, &src, gpScreen, &dst);
    
    src.x = 112;
    for (int i = 8; i < w-8; i+=16) {
        dst.x = x+i; src.w=16;
        while (dst.x + src.w > x+w && src.w>0) src.w--;
        if (src.w>0) SDL_BlitSurface(imageFont, &src, gpScreen, &dst);
    }
    
    src.w=8; src.x = 129; dst.x = x+w-8;
    SDL_BlitSurface(imageFont, &src, gpScreen, &dst);
}

void Texte::setTexte(int idTxt, int vx, int vy, int vw, int vh, bool cadr, bool defil, int vit) {
    if (idTxt == 0) return;
    id = idTxt; 
    idsuiv = 0;
    buffer = "";
    chercheText();
    
    x = vx; y = vy; w = vw; h = vh;
    decoupeText();
        
    def=defil;
    if (def) av = 0;
    else av = texte.length();
    
    cadre = cadr;
    
    vitesse = vit;
}

void Texte::decoupeText() {
    //compte le nombre de caract�res possibles et largeur et en hauteur
    int nbcol = (w-16)/6 -1;
    int nblig = (h-16)/16;
    int tailleMax = nbcol * nblig;
    int taille;
    
    //parcours du texte � afficher; � chaque d�but de mot, 
    //v�rifie que le mot peut tenir sur la ligne
    for (int i = 0; i < (int)texte.length(); i++) {
        
        //supprime les espaces isol�s en d�but de ligne
        if (texte.at(i)==' ' && texte.at(i+1)!=' ' && i%nbcol == 0) texte.erase(i,1);
        //recherche du d�but du prochain mot
        while(texte.at(i)==' ' && i < (int)texte.length()-1) i++;
        
        //saute une ligne si trouve une �toile
        if (texte.at(i)=='*') {
            texte.erase(i,1);//replace(i, 1, " ");
            int nb = (nbcol)-(i%(nbcol));
            for (int j = 0; j < nb; j++) texte.insert(i," ");
            continue;
        }
        
        //si le mot d�passe
        taille = tailleMot(i);
        if ((i%nbcol)+taille>nbcol) {
            if  (i < tailleMax) {
                //si le mot ne tient pas sur une ligne, on le coupe avec des tirets
                if (taille>nbcol) {
                    texte.insert(((i/nbcol)+1)*nbcol-1,"--");
                    i = 1+((i/nbcol)+1)*nbcol;
                }
                //sinon, on ajoute des espaces pour faire commencer le mot � la ligne
                else while((i%nbcol) != 0) {texte.insert(i," "); i++;}
            }
        }
        
    }
    
    // si le texte est trop grand, on le coupe en deux
    if ((int)texte.length() > tailleMax) {
        buffer2 = texte.substr(tailleMax);
        texte = texte.substr(0, tailleMax);
    }
}

int Texte::tailleMot(int deb) {
    int i = deb;
    int total = 0;
    while (texte.at(i)!=' ') {total++; i++; if (i >= (int)texte.length()) return total;}
    return total;
}

void Texte::afficheLettre(SDL_Surface* gpScreen, char c, int vx, int vy) {
    SDL_Rect src;
    SDL_Rect dst;
    
    int val = (int)c;
    
    dst.x=vx; dst.y=vy;
    src.h=16;src.w=8;
    
    if(val==32) return;

    // es
    // �
    if(val=='�') {src.x=164;src.y=68;}
    // �
    if(val=='�') {src.x=164;src.y=103;}
    // �
    if(val=='�') {src.x=164;src.y=52;}
    // �
    if(val=='�') {src.x=164;src.y=84;}
	
	// not spanish was a bug
    //// �
    //if(val=='�') {src.x=164;src.y=151;}
    
	// de
    // �
    if(val=='�') {src.x=6+16*3; src.y=167;}
    
    // �
    if(val=='�') {src.x=6; src.y=167;}
    
    // �
    if(val=='�') {src.x=6+16; src.y=167;}
    
    // �
    if(val=='�') {src.x=6+16*2; src.y=167;}
    

    // it
    // �
    if(val=='�') {src.x=164;src.y=36;}
    // �
    if(val=='�') {src.x=164;src.y=119;}
 
	// hu - start
	// � - ok in spanish
	// � - ok in french
	// � - ok in spanish
	// � - ok in spanish
	// � - ok in german
	// � - nincs
	if(val=='�') {src.x=164;src.y=135;}
	// �
	if(val=='�') {src.x=164;src.y=151;}
	// � - ok in french
	// � - ok in french
	// -----
	// �	
    if(val=='�') {src.x=6+16*4; src.y=167;}
	// �
	if(val=='�') {src.x=6+16*9; src.y=167;}	
	// � 
	if(val=='�') {src.x=6+16*10; src.y=167;}	
	// �	
    if(val=='�') {src.x=6+16*5; src.y=167;}
    // � - ok in german 
	// �
    if(val=='�') {src.x=6+16*7; src.y=167;}	
	// �
    if(val=='�') {src.x=6+16*6; src.y=167;}
	// � - ok in german
	// �
	if(val=='�') {src.x=6+16*8; src.y=167;}	
	// hu - end

    // /
    if(val==47) {src.x=52;src.y=151;}
    
    // @ hylien
    if(val==64) {src.x=4;src.y=151;}
            
    // + hylien
    if(val==43) {src.x=20;src.y=151;}
            
    // = hylien
    if(val==61) {src.x=36;src.y=151;}
            
    //minuscules a-z
    if(val>=97 && val<=122) {src.x=4+16*((val-97)%10); src.y=52+16*((val-97)/10);}
            
    //majuscules A-Z
    if(val>=65 && val<=90) {src.x=6+16*((val-65)%10); src.y=2+16*((val-65)/10);}   
    // �
    if(val=='�') {src.x=148;src.y=34;}
    // �
    if(val=='�') {src.x=100;src.y=84;}
    // �
    if(val=='�') {src.x=116;src.y=84;}
    // �
    if(val=='�') {src.x=132;src.y=84;}
    // �
    if(val=='�') {src.x=132;src.y=151;}
    // �
    if(val=='�') {src.x=148;src.y=84;}
    // �
    if(val=='�') {src.x=148;src.y=103;}
    // �
    if(val=='�') {src.x=148;src.y=135;}
    // �
    if(val=='�') {src.x=84;src.y=119;}
    // �
    if(val=='�') {src.x=116;src.y=151;}
    // �
    if(val=='�') {src.x=84;src.y=103;}
    // �
    if(val=='�') {src.x=148;src.y=151;}
    // �
    if(val=='�') {src.x=116;src.y=135;}
    // �
    if(val=='�') {src.x=132;src.y=135;}
    // �
    if(val=='�') {src.x=148;src.y=119;}
            
    //ponctuation
    // -
    if(val==45) {src.x=102;src.y=34;}
    // .
    if(val==46) {src.x=118;src.y=34;}
    // ,
    if(val==44) {src.x=134;src.y=34;}
    // !
    if(val==33) {src.x=3;src.y=135;}
    // ?
    if(val==63) {src.x=19;src.y=135;}
    // (
    if(val==40) {src.x=35;src.y=135;}
    // )
    if(val==41) {src.x=51;src.y=135;}            
    // ' ( avec @ )
    if(val==39) {src.x=67;src.y=135;}
    // :
    if(val==58) {src.x=83;src.y=135;}
    // ... ( avec % )
    if(val==37) {src.x=101;src.y=135;}
    // >
    if(val==62) {src.x=100;src.y=151;}
    // <
    if(val==60) {src.x=84;src.y=151;}
            
    //chiffres // numbers           
    if(val>=48 && val<=57) {src.x=3+16*((val-48)%5); src.y=103+16*((val-48)/5);}
    
    SDL_BlitSurface(imageFont, &src, gpScreen, &dst);
}

bool Texte::hasNext() {
    return (buffer2 != "" ||buffer != "" || idsuiv > 0);
}

bool Texte::suite() {
    if (av < (int)texte.length()) {
        av = texte.length();
        return true;
    }
    if (!hasNext()) {
        gpJeu->getAudio()->playSound(18);
        return gpJeu->finTexte(id);
    }
    if (buffer2 != "") {
        texte = buffer2;
        buffer2 = "";
    }
    else if (buffer != "") {
        texte = buffer;
        buffer = "";
    }
    else {
        id = idsuiv;
        idsuiv = 0;
        chercheText();
    }
    decoupeText();
    if (def) av = 0;
    else av = texte.length();
    gpJeu->getAudio()->playSound(17);
    return true;
}
