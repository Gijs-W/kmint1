#include "Gun.h"
#include "Instance.h"


Gun::Gun()
{
}

void Gun::Update(Instance* instance, float deltatime){
	Move(0.0f);
}

Gun::~Gun()
{
}
