package dengue

class Regiao {
	String regiao;

    static constraints = {
    	regiao(blank:false, inList:["Norte", "Nordeste", "Sudeste", "Sul", "Centro-Oeste"])
    }
}
