
// Conteneur STL -> Standard Template Library
// Insertion rapide par l'avant ou par l'arriere.
// Random access operator
#include <vector>
#include <iostream>

#include "Cochon.h"
#include "Vache.h"
#include "Poule.h"

#define NUM_ANIMAL 3

#include "Engine.h"
#include "Renaud.h"
#include "TextManager.h"
#include "TestEnvironment.h"


int main(int argc, char* args[])
{
	#pragma region Engine Tests

	GEngine->Init("TestEnvironment", 800, 600);

	// Creation de nos objets de jeu.
	Sprite* sprite= new Sprite("Images\\JeSuisRenaud.png");
	Renaud* renaud = new Renaud();
	//TextManager* test = new TextManager();
	TestEnvironment* env = new TestEnvironment();
	
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);


	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody; 
	myBodyDef.position.Set(0, 20); 
	myBodyDef.angle = 0;

	b2Body* myBody;

	myBody = world.CreateBody(&myBodyDef);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(1, 1);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	myBody->CreateFixture(&boxFixtureDef);


	GEngine->Run();

	delete renaud;

	#pragma endregion

	return 0;
}