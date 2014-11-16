#ifndef VECTEUR_H
#define VECTEUR_H

class Vecteur{

private:

    double _deplacementX, _deplacementY;
public:

    Vecteur(double deplacementX, double deplacementY):
        _deplacementX(deplacementX),
        _deplacementY(deplacementY)
    {}

    double getDeplacementX()const{return _deplacementX;}
    double getDeplacementY()const{return _deplacementY;}
    Vecteur operator* (const Vecteur& v);
    double norme()const;
};

#endif // VECTEUR_H
