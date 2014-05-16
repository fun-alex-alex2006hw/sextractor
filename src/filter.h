/*
*				filter.h
*
* Include file for filter.c.
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*
*	This file part of:	SExtractor
*
*	Copyright:		(C) 1993-2010 Emmanuel Bertin -- IAP/CNRS/UPMC
*
*	License:		GNU General Public License
*
*	SExtractor is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*	SExtractor is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*	You should have received a copy of the GNU General Public License
*	along with SExtractor. If not, see <http://www.gnu.org/licenses/>.
*
*	Last modified:		11/10/2010
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*------------------------------- definitions -------------------------------*/

#define	MAXMASK		1024	/* Maximum number of mask elements (=32x32) */

/*------------------------------- structures --------------------------------*/

typedef struct structfilter
  {
/*---- convolution */
  float		*conv;		/* pointer to the convolution mask */
  int		nconv;		/* total number of elements */
  int		convw, convh;	/* x,y size of the mask */
  float		varnorm;
/*---- neural filtering */
  struct structbpann	*bpann;
  }	filterstruct;

filterstruct	*thefilter;

/*------------------------------- functions ---------------------------------*/
void		convolve(fieldstruct *, PIXTYPE *, int y),
		convolve_image(fieldstruct *field, float *vig1,
				float *vig2, int width, int height),
		filter(fieldstruct *, PIXTYPE *, int y),
		neurfilter(fieldstruct *, PIXTYPE *, int y),
		endfilter(void);


extern int  getneurfilter(const char *filename);
extern void getfilter(const char *filename);
extern int	getconv(const char *filename);
extern int  getASCIIconv(const char *filename);
extern int  getPSFExconv(const char *filename);
extern void getImageStats(const float *pix, const int width, const int height, float stats[]);
