/* The MIT License (MIT)
 * Copyright (c) 2013 Andrea Francesco Iuorio
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

double __pCordicValue[2];

#define NUM_ITERATION 35

double __cordicAngles [] =  {
    		0.785398163397448, 0.463647609000806, 0.244978663126864, 0.124354994546761, 0.062418809995957, 0.031239833430268, 0.015623728620477,
 			0.007812341060101, 0.003906230131967, 0.001953122516479, 0.000976562189559, 0.000488281211195, 0.000244140620149, 0.000122070311894,
 			0.000061035156174, 0.000030517578116, 0.000015258789061, 0.000007629394531, 0.000003814697266, 0.000001907348633, 0.000000953674316,
 			0.000000476837158, 0.000000238418579, 0.000000119209290, 0.000000059604645, 0.000000029802322, 0.000000014901161, 0.000000007450581,
 			0.000000003725290, 0.000000001862645, 0.000000000931323, 0.000000000465661, 0.000000000232831, 0.000000000116415, 0.000000000058208,
 			0.000000000029104, 0.000000000014552, 0.000000000007276, 0.000000000003638, 0.000000000001819, 0.000000000000909, 0.000000000000455,
 			0.000000000000227, 0.000000000000114, 0.000000000000057, 0.000000000000028, 0.000000000000014, 0.000000000000007, 0.000000000000004,
 			0.000000000000002 };

void __pCordic(double x){
	__pCordicValue[0] = 1;
	__pCordicValue[1] = 0;	/*Standard vector*/

	double ang = __cordicAngles[0];
	double newX, newY;
	double powerTwo = 1;
	double sign;
	register unsigned int i;

	for(i=0; i < NUM_ITERATION; i++){
		sign = x < 0 ? -1.0: 1.0;
		x -= sign * ang;	/*x is the error between my angle and the ang actually used by the algorithm. With this, i can know the direction of the next rotation*/
		ang = __cordicAngles[i+1];
		/*Maybe i can use a SIMD instruction here ?*/
		newX = __pCordicValue[0] - ( __pCordicValue[1] * sign * powerTwo );	//Moltiplication with the rotation matrix.
		newY = ( __pCordicValue[0] * sign * powerTwo ) + __pCordicValue[1];
		powerTwo /= 2;
		__pCordicValue[0] = newX;
		__pCordicValue[1] = newY;
	}
	__pCordicValue[0]*=0.60725293500888;	//cos
	__pCordicValue[1]*=0.60725293500888;	//sin.
}
