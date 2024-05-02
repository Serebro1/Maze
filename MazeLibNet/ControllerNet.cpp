#include "ControllerNet.h"
void ControllerNet::step(int val)
{
	switch (val)
	{
	case 40:
		gmNet->move(DOWN);
		break;
	case 38:
		gmNet->move(UP);
		break;
	case 37:
		gmNet->move(LEFT);
		break;
	case 39:
		gmNet->move(RIGHT);
		break;
	}
}