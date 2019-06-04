{

for (int i = 1; i < 82; i++){

	makeStack("ht", "ht", Form("eventBin == %d && numJets == 4", i), 100,0,7000, Form("bin%d", i), Form("bin%d",i));
}


}
