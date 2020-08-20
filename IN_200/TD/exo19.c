#include "uvsqgraphics.h"

struct raquette
{
	POINT centre;
	int longeur;
	int largeur;
	COULEUR coul;
	
};

typedef struct raquette RAQUETTE;



RAQUETTE init_raquette()
{
	RAQUETTE r;
	r.centre.x = 400 ;
	r.centre.y = 100 ;
	r.longeur = 40 ;
	r.largeur = 10 ;
	r.coul = gris;
	
	
	return r;	
}

RAQUETTE deplace_raquette(RAQUETTE r)
{
	POINT a; int d,g;
	d = r.centre.x +(r.longeur/2);
	g = r.centre.x -(r.longeur/2);
	a = get_arrow();
	if ( a.x <0)
	{
		if (g > 0)
		{
			r.centre.x += a.x*1.5;
		}
		else
		{
		}
	}
	else if ( a.x > 0)
	{
		if (d < 800)
		{
			r.centre.x += a.x*1.5;
		}
		else
		{
		}
		
	}
	printf("<<< %d\n", r.centre.x);
	return r;
}

void affiche_raquette(RAQUETTE r)
{
	POINT a,b;
	a.x = r.centre.x - (r.longeur/2); a.y = r.centre.y - (r.largeur/2);
	b.x = r.centre.x + (r.longeur/2); b.y = r.centre.y + (r.largeur/2);
	draw_fill_rectangle(a,b,r.coul);
}

void efface_raquette(RAQUETTE r)
{
	POINT a,b;
	a.x = r.centre.x - (r.longeur/2); a.y = r.centre.y - (r.largeur/2);
	b.x = r.centre.x + (r.longeur/2); b.y = r.centre.y + (r.largeur/2);
	draw_fill_rectangle(a,b,noir);
}


int main()
{
init_graphics(800,800);

// Debut du code
RAQUETTE r; int i;
r = init_raquette();
affiche_raquette(r);
wait_clic();
affiche_auto_off();
i = 0;
while (i == 0)
{
	efface_raquette(r);
	r = deplace_raquette(r);
	affiche_raquette(r);
	affiche_all();
}



// Fin du code

wait_escape();
exit(0);
}
