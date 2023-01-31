#include "ShopService.h"

ShopService::ShopService()
{
	shop = Shop();
	service = ShopService();
}

void ShopService::visit_client(int type_of_visit, string clientName)
{
	if (type_of_visit)
		service.EnterClient(clientName);
	else
		//

}
