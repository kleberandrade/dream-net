#include "NetworkData.h"

NetworkData::NetworkData(void){

}

NetworkData::~NetworkData(void){

}

void NetworkData::Serialize(char *data){


	OnSerialize(data);	
}

void NetworkData::Deserialize(char *data){


	OnDeserialize(data);
}