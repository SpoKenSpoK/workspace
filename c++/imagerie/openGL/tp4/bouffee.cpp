#include "bouffee.hpp"
#include "texture.hpp"

Bouffee::Bouffee(float _xpos, float _ypos, float _zpos, float _taille, float _vitesse_x, float _vitesse_y, float _vitesse_z, float _vie)
    :xpos(_xpos), ypos(_ypos), zpos(_zpos), taille(_taille), vitesse_x(_vitesse_x), vitesse_y(_vitesse_y), vitesse_z(_vitesse_z), vie(_vie)
{}

void Bouffee::anime(float temps){
    xpos += xpos + vitesse_x * temps;
    ypos += ypos + vitesse_y * temps;
    zpos += zpos + vitesse_z * temps;
    vie -= temps;
}

void Bouffee::affiche(){
    // Comme on ne veut pas que ce quadrilatère soit affecté
    // par la lumière, on désactive l’éclairage juste avant
    // de l’afficher, et on le réactivera juste après. Vous
    // n’aurez donc pas besoin de spécifier la normale du
    // quadrilatère
    glDisable(GL_LIGHTING);
    // On veut pouvoir voir les deux côtés du quadrilatère
    glDisable(GL_CULL_FACE);
    // On active le blending pour que la couleur de la texture
    // se mélange à la couleur du reste de la scène dans des
    // proportions données par la valeur alpha de chaque texel
    // de la texture
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    // Affichage du quadrilatère texturé avec la texture RGBA
    // glBegin(GL_QUADS)
    // ...
    // glEnd()
    Texture texture;
    texture.charger("fumee.tga");
    texture.definir_filtrage(GL_LINEAR, GL_LINEAR);
	texture.definir_bouclage(GL_CLAMP, GL_CLAMP);
	texture.definir_melange(GL_MODULATE);
    texture.utiliser();

    glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(xpos-taille/2, ypos, zpos-taille/2);
        glTexCoord2f(0,1);
        glVertex3f(xpos+taille/2, ypos, zpos-taille/2);
        glTexCoord2f(1,1);
        glVertex3f(xpos+taille/2, ypos, zpos+taille/2);
        glTexCoord2f(1,0);
        glVertex3f(xpos-taille/2, ypos, zpos+taille/2);
    glEnd();

    // On désactive le blending
    glDisable(GL_BLEND);
    // On reactive l’utilisation de la lumière
    glEnable(GL_LIGHTING);
    // Pour ne voir qu’un seul côté des polygones
    glEnable(GL_CULL_FACE);
}
