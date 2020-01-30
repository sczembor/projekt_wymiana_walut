
output: main.o Admin.o Authorization.o Client.o Currency.o CurrencyRates.o Exchange.o HttpReq.o JSONParser.o List.o Node.o User.o Wallet.o
	g++ main.o Admin.o Authorization.o Client.o Currency.o CurrencyRates.o Exchange.o HttpReq.o JSONParser.o List.o Node.o User.o Wallet.o -output

main.o: main.cpp
	g++ -c main.cpp

Authorization.o: Authorization.cpp Authorization.hpp
	g++ -c Authorization.cpp

Client.o: Client.cpp Client.hpp
	g++ -c Client.cpp

Currency.o: Currency.cpp Currency.hpp
	g++ -c Currency.cpp

CurrencyRates.o: CurrencyRates.cpp CurrencyRates.hpp
	g++ -c CurrencyRates.cpp

Exchange.o: Exchange.cpp Exchange.hpp
	g++ -c Exchange.cpp

HttpReq.o: HttpReq.cpp HttpReq.hpp
	g++ -c HttpReq.cpp

JSONParser.o: JSONParser.cpp JSONParser.hpp
	g++ -c JSONParser.cpp

List.o: List.cpp List.hpp
	g++ -c List.cpp

Node.o: Node.cpp Node.hpp
	g++ -c Node.cpp

User.o: User.cpp User.hpp
	g++ -c User.cpp

Wallet.o: Wallet.cpp Wallet.hpp
	g++ -c Wallet.cpp
	

clean:
	rm *.o output