#include "pch.h"
#include "Struct.h"


namespace structure {
	String^ structure::Address::ToString()
	{
		String^ ConcatanedString;
		ConcatanedString += streetNum;
		ConcatanedString += " ";
		ConcatanedString += streetName;
		ConcatanedString += " ";
		ConcatanedString += cityCode;
		ConcatanedString += " ";
		ConcatanedString += cityName;
		return ConcatanedString;
	}

	String^ ProductData::ToString() {
		return "ProductData{ref=" + ref + ";nom=" + name + ";prix_UHT=" + priceNoTax + ";valeur_achat=" + purchaseValue +
			";qtté=" + amount + ";TVA=" + TVARatio + ";remise=" + discountRatio + ";seuil_reappro=" + restockThreshold + "}";
	}

	String^ Payment::ToString()
	{
		String^ mean_str;
		switch (mean) {
		case PaymentMean::Cash:
			mean_str = "Espèces";
			break;
		case PaymentMean::CreditCard:
			mean_str = "CB";
			break;
		default:
			mean_str = "<Inconnu>";
		}
		String^ ConcatanedString;
		ConcatanedString += mean_str;
		ConcatanedString += ", ";
		ConcatanedString += receptionDate;
		ConcatanedString += ", ";
		ConcatanedString += paymentDate;
		return ConcatanedString;
	}
	String^ StaffSelector_Row::ToString()
	{
		return this->lname + " " + this->fname;
	}
}


