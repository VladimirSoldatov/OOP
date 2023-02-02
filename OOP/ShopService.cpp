#include "ShopService.h"

ShopService::ShopService(string _nameOrganization)
{
	shop = Shop();
	service = Service();
	nameOrganization = _nameOrganization;
}

void ShopService::visit_client(int type_of_visit, string clientName)
{
	if (type_of_visit)
		service.EnterClient(clientName);
	else
		//

}
