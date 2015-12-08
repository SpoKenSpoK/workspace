#include <iostream>
#include "image.hpp"

int main(){
	//GrayImage i; //>Déclanche une erreur
	GrayImage i(400,300);
	i.clear();
	
	ColorImage cc(420,610);
	Color color(164,35,120);
	cc.clear(color);
	
	i.fillRectangle(11,120,120,150, 255);
	i.rectangle(10,10,122,152,210);

	std::ofstream f("test.pgm", std::ios::out | std::ios::binary);
	std::ofstream k("bruh.pgm", std::ios::out | std::ios::binary);
	std::ofstream h("z.pgm", std::ios::out | std::ios::binary);
	std::ofstream g("test_.pgm", std::ios::out | std::ios::binary);
	std::ofstream imgcolor("color.ppm", std::ios::out | std::ios::binary);


	GrayImage* z = i.simpleScale(420,310);
	GrayImage* w = i.bilinearScale(560,210);

	i.writePGM(f);
	z->writePGM(h);
	w->writePGM(k);
	
	cc.writePPM(imgcolor);

	std::ifstream is("test.pgm", std::ios::in | std::ios::binary);
	GrayImage* pi = GrayImage::readPGM(is);

	pi->writePGM(g);

	delete pi;
	delete z;
	delete w;				
       				
	f.close();
	g.close();
	is.close();
	k.close();
	h.close();
	imgcolor.close();

	return 0;
}
