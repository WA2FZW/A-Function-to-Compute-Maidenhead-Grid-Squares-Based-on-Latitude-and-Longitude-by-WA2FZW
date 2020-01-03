# A-Function-to-Compute-Maidenhead-Grid-Squares-Based-on-Latitude-and-Longitude-by-WA2FZW
GetGridSquare ()
By: John Price (WA2FZW) Jan 03, 2020


This function computes the 6-character Maidenhead grid square based on the latitude
and longitude. The arguments are:
 
		double	latitude
		double	longitude
		char*	buffer (at least 7 long)

The latitude and longitude are in the NMEA format. In other words, West longitudes 
and South latitudes are negative numbers. They are specified as "double" types as
that is the type used by the TinyGPS++ library that I use with this.

The buffer in which the grid square designation is constructed must have space for
at least 7 characters (6 for the grid square string plus a null terminator).
	
A great explanation of the math can be found here:

	http://n1sv.com/PROJECTS/How%20to%20calculate%20your%208-digit%20grid%20square.pdf

	
The function can be used on any platform, however please note that the accuracy cannot
be assured when using it on an Arduino as I have found that the floating point
computations on the Arduino are not 100% accurate.
