#include <stdlib.h>
#include <iostream>
#include "stdafx.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
using namespace std;

const string server = "";
const string username = "";
const string password = "";

int main()
{
	//CONNESSIONE
    sql::Driver *driver;
    sql::Connection *con;
    sql::PreparedStatement *pstmt;
    sql::ResultSet *result;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "ERROR MESSAGE: impossibile connettersi " << e.what() << endl;
        system("pause");
        exit(1);
    }

    con->setSchema("quickstartdb");

    //QUERY 1  
    pstmt = con->prepareStatement("SELECT ACQUISTA.CF_CLIENTE, sum(case when ORDINE.ONLINE_='1' THEN 1 ELSE 0 END) AS TOT_ORDINI FROM ACQUISTA INNER JOIN ORDINE ON ACQUISTA.ORDINE=ORDINE.COD GROUP BY CF_CLIENTE ORDER BY TOT_ORDINI DESC LIMIT 10");
	result = pstmt->executeQuery();

    while (result->next())
        printf(result->getInt(1), result->getString(2).c_str(), result->getInt(3));

    delete result;
    delete pstmt;
    delete con;
    system("pause");
    return 0;

    //QUERY 2  
    pstmt = con->prepareStatement("SELECT COUNT(ACQUISTA.ORDINE) AS TOT_ORDINI, SUM(PRODOTTO.PREZZO) AS LORDO FROM PRODOTTO INNER JOIN ACQUISTA ON PRODOTTO.COD=ACQUISTA.PRODOTTO INNER JOIN ORDINE ON ORDINE.COD=ACQUISTA.ORDINE WHERE PRODOTTO.COD=ACQUISTA.PRODOTTO 	AND ORDINE.DATA_ACQUISTO BETWEEN '2022-01-01' AND '2022-06-30'");
    result = pstmt->executeQuery();

    while (result->next())
        printf(result->getInt(1), result->getString(2).c_str(), result->getInt(3));

    delete result;
    delete pstmt;
    delete con;
    system("pause");
    return 0;
	
    //QUERY 3  
    pstmt = con->prepareStatement("SELECT VIDEOGIOCO.GENERE, COUNT(ACQUISTA.ORDINE) AS GIOCHI_VENDUTI, SUM(PRODOTTO.PREZZO) AS INCASSO FROM ACQUISTA INNER JOIN PRODOTTO ON PRODOTTO.COD=ACQUISTA.PRODOTTO INNER JOIN VIDEOGIOCO ON PRODOTTO.COD=VIDEOGIOCO.COD_PRODOTTO GROUP BY VIDEOGIOCO.GENERE");
    result = pstmt->executeQuery();

    while (result->next())
        printf(result->getInt(1), result->getString(2).c_str(), result->getInt(3));

    delete result;
    delete pstmt;
    delete con;
    system("pause");
    return 0;

    //QUERY 4  
    pstmt = con->prepareStatement("SELECT ACCEDERE.SALA_LAN, COUNT(ACCEDERE.ABBONATO) AS NUMERO_ABBONATI FROM ACCEDERE INNER JOIN CLIENTE ON ACCEDERE.ABBONATO=CLIENTE.CF WHERE CLIENTE.TESSERA='LV3' GROUP BY ACCEDERE.SALA_LAN ORDER BY NUMERO_ABBONATI DESC");
    result = pstmt->executeQuery();

    while (result->next())
        printf(result->getInt(1), result->getString(2).c_str(), result->getInt(3));

    delete result;
    delete pstmt;
    delete con;
    system("pause");
    return 0;
	
    //QUERY 5  
    pstmt = con->prepareStatement("SELECT LAN_PARTY.OMAGGIO, COUNT(ACCEDERE.ABBONATO) AS TOT_PRESENTI, SUM(TESSERA.PREZZO) AS INCASSI_DA_TESSERA FROM LAN_PARTY INNER JOIN ACCEDERE ON LAN_PARTY.SALA=ACCEDERE.SALA_LAN INNER JOIN CLIENTE ON ACCEDERE.ABBONATO=CLIENTE.CF INNER JOIN TESSERA ON CLIENTE.TESSERA=TESSERA.LIVELLO GROUP BY LAN_PARTY.OMAGGIO");
    result = pstmt->executeQuery();

    while (result->next())
        printf(result->getInt(1), result->getString(2).c_str(), result->getInt(3));

    delete result;
    delete pstmt;
    delete con;
    system("pause");
    return 0;
	
    //QUERY 6  
    pstmt = con->prepareStatement("SELECT DISTINCT NEGOZIO.COD, COUNT(ORDINE.COD) AS ORDINI_FISICI FROM NEGOZIO INNER JOIN ORDINE ON NEGOZIO.COD=ORDINE.COD_NEGOZIO WHERE ORDINE.ONLINE_='0'  AND NEGOZIO.COD=ORDINE.COD_NEGOZIO GROUP BY NEGOZIO.COD");
    result = pstmt->executeQuery();

    while (result->next())
        printf(result->getInt(1), result->getString(2).c_str(), result->getInt(3));

    delete result;
    delete pstmt;
    delete con;
    system("pause");
    return 0;
}
