/*
 *	GetGridSquare ()	By: John Price (WA2FZW)
 *
 *	This function computes the 6-character Maidenhead grid square based on the latitude
 *	and longitude. The arguments are:
 *
 *		double	latitude
 *		double	longitude
 *		char*	buffer (at least 7 long)
 *
 *	The latitude and longitude are in the NMEA format. In other words, West longitudes 
 *	and South latitudes are negative numbers. They are specified as "double" types as
 *	that is the type used by the TinyGPS++ library that I use with this.
 *
 *	The buffer in which the grid square designation is constructed must have space for
 *	at least 7 characters (6 for the grid aquare plus a null terminator).
 *	
 *	A great explanation of the math can be found here:
 *
 *		http://n1sv.com/PROJECTS/How%20to%20calculate%20your%208-digit%20grid%20square.pdf
 */

void GetGridSquare ( double _lat, double _long, char* buff )
{

double	tempNumber;									// Used in the intermediate computations
int		index;										// Index to the above arrays

/*
 *	First compute the first 2 characters:
 */

		_long += 180;								// 360 degrees starting from middle of the Pacific
		tempNumber = _long / 20;					// Each major square is 20 degrees wide
		index = (int) tempNumber;					// The index to the "upperCase" array
		buff[0] = index + 'A';						// Set first character
		_long = _long - ( index * 20 );				// Remainder for step 2

		_lat += 90;									// 180 degrees starting from the South pole
		tempNumber = _lat / 10;						// Each major square is 10 degrees high
		index = (int) tempNumber;					// The index to the "upperCase" array
		buff[1] = index + 'A';						// Set second character
		_lat = _lat - ( index * 10 );				// Remainder for step 2


/*
 *	Now the 2nd two digits:
 */

		tempNumber = _long / 2;						// Remainder from step 1 divided by 2
		index = (int) tempNumber;					// The index to the "digits" array
		buff[2] = index + '0';						// Set third character
		_long = _long - ( index * 2 );				// Remainder for step 3

		tempNumber = _lat;							// Remainder from step 1 divided by 1
		index = (int) tempNumber;					// The index to the "digits" array
		buff[3] = index + '0';						// Set fourth character
		_lat = _lat - index;						// Remainder for step 3


/*
 *	Now the third two characters:
 */

		tempNumber = _long / 0.083333;				// Remainder from step 2 divided by 0.083333
		index = (int) tempNumber;					// The index to the "lowerCase" array
		buff[4] = index + 'a';						// Set fifth character

		tempNumber = _lat / 0.0416665;				// Remainder from step 2 divided by 0.0416665
		index = (int) tempNumber;					// The index to the "digits" array
		buff[5] = index + 'a';						// Set fifth character

		buff[6] = '\0';								// Null terminator
}
