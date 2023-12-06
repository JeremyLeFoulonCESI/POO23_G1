#include "pch.h"
#include "Table.h"


namespace Components {
    
    Table^ Table::getStaffTable()
    {
        String^ name = "Personnel";
        array<String^>^ primaryKeys = gcnew array<String^> { "ID" }; 
        array<String^>^ keys = gcnew array<String^> { "Nom", "Prenom", "DateEmbauche", "ID_Adresse", "ID_Superieur" };

        return gcnew Table(name, primaryKeys, keys);
    }

    Table^ Table::getCityTable()
    {
        String^ name = "Ville";
        array<String^>^ primaryKeys = gcnew array<String^> { "ID" };
        array<String^>^ keys = gcnew array<String^> { "NomVille", "CodePostal" };

        return gcnew Table(name, primaryKeys, keys);
    }

    Table^ Table::getAddressTable()
    {
        String^ name = "Adresse";
        array<String^>^ primaryKeys = gcnew array<String^> { "ID" };
        array<String^>^ keys = gcnew array<String^> { "NumRue", "Rue", "ID_Ville", "CodeClient_ClientLivre", "CodeClient_ClientFacture" };

        return gcnew Table(name, primaryKeys, keys);
    }

    Table^ Table::getCustomerTable()
    {
        String^ name = "Clients";
        array<String^>^ primaryKeys = gcnew array<String^> { "CodeClient" };
        array<String^>^ keys = gcnew array<String^> { "Nom", "Prenom", "DateNaissance", "AdresseMail", "NumTel", "DatePremierAchat" };

        return gcnew Table(name, primaryKeys, keys);
    }

    Table^ Table::getOrderTable()
    {
        String^ name = "Commande";
        array<String^>^ primaryKeys = gcnew array<String^> { "ID" };
        array<String^>^ keys = gcnew array<String^> { "Reference", "DateLivraison", "DateEmission", "CodeClient" };

        return gcnew Table(name, primaryKeys, keys);
    }

    Table^ Table::getContainsTable()
    {
        String^ name = "Contient";
        array<String^>^ primaryKeys = gcnew array<String^> { "ID_Commande", "Reference_Article" };
        array<String^>^ keys = gcnew array<String^> { "NbArticles", "TauxRemises", "TauxTVA", "PrixUHT" };

        return gcnew Table(name, primaryKeys, keys);
    }

    Table^ Table::getProductTable()
    {
        String^ name = "Articles";
        array<String^>^ primaryKeys = gcnew array<String^> { "Reference" };
        array<String^>^ keys = gcnew array<String^> { "Nom", "PrixUHT", "PrixUA", "Quantité", "TauxTVA", "TauxRemises", "SeuilReapro" };

        return gcnew Table(name, primaryKeys, keys);
    }

    Table^ Table::getPaymentTable()
    {
        String^ name = "Paiement";
        array<String^>^ primaryKeys = gcnew array<String^> { "ID" };
        array<String^>^ keys = gcnew array<String^> { "MoyenPaiement", "DateEncaissement", "DatePaiement", "ID_Commande" };

        return gcnew Table(name, primaryKeys, keys);
    }
}

