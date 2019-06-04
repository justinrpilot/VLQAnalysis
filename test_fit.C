{

float bins[] = { 1200, 1500,2500,4000,6000};

TH1F *hist = new TH1F("test", "test", 4, bins);


hist->Fill(1250, 0.925);
hist->Fill(1700, 0.975);
hist->Fill(3000, 0.905);
hist->Fill(5000, 0.900);
hist->SetMinimum(0.0);
hist->SetMaximum(1.0);
hist->Draw("hist");

}
