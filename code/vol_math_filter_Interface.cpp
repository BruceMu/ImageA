#include "vol_math_filter_Interface.h"
#include "vol_math_FourierFilter3.h"
//qym
#include "vol_math_RawImage.h"
using namespace std;

 void *dolowPassI (ImageVolume *src,lowPassI &para)
{
	Raw indata = *(Raw *)ImageVolume2Raw(src);
	FourierFilter3 * ff3 = new FourierFilter3(indata);
	ff3->lowpass_trans(para.threshold/*,progress*/);
	Raw * ret= new Raw(*(ff3->fraw),true);
	delete ff3;
	return ret;
}
