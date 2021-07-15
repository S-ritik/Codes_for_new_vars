void plot(string file, string hist, string var)
{
  TFile *f;
  f= new TFile(file.c_str());

  TH1D *h=(TH1D*)f->Get(hist.c_str());
  h->SetFillColor(2);
  h->SetLineWidth(2);
  h->SetMarkerStyle(8);
  h->GetYaxis()->SetTitle("Number of events");
  h->GetXaxis()->SetTitle(var.c_str());
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->CenterTitle();
  h->GetXaxis()->SetTickLength(0.05);
  h->GetXaxis()->SetTickLength(0.05);
  //hs4->GetXaxis()->SetNdivisions(120);
  h->GetXaxis()->SetLabelSize(0.03);
  h->GetXaxis()->SetTitleSize(0.04);
  h->GetXaxis()->SetTitleOffset(1.1);
  h->GetXaxis()->SetLabelOffset(.02);
  h->GetYaxis()->SetLabelSize(0.025);
  h->GetYaxis()->SetTitleSize(0.05);
  h->GetYaxis()->SetTitleOffset(0.8);
  h->GetYaxis()->SetLabelOffset(.01);

  Double_t scale = 1.0/h->Integral();
  h->Scale(scale);
  
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  TCanvas* c=new TCanvas("c","plot",900,600);
  c->cd();
  
  //gPad->SetLogy();
  //if(strstr(hist.c_str(),"pT") ||strstr(hist.c_str(),"HT"))
  // gPad->SetLogx();
  h->Draw("e2");
  string pname;
  pname="plot_"+hist+".jpg";
  c->Update();
  c->SaveAs(pname.c_str());
  delete c;
}

void plot_one_var()
{
    const char *new_var_names[16] = {"hist_genMET","hist_phi(genlep1)","hist_phi(genlep2)","hist_phi(genMET)","hist_HT(AK4jets)","hist_pT(genlep1)","hist_pT(genlep2)","hist_pT(genjetAK4)", "hist_pT(gen_b)","hist_deltaPhi(genMET,genlep1)","hist_deltaPhi(genMET,genlep2)","hist_deltaPhi(genMET,genjetAK4)","hist_deltaPhi(genMET,gen_b)","hist_mT(genlep1)","hist_mT(genlep2)","hist_R_(m)"};

  const char *new_var_title[16] = {"gen MET","#phi of leading gen lep","#phi of second leading gen lep","#phi(gen E^{mis}_{T})","H_{T} of AK4 jets","p_{T} of leading gen lep","p_{T} of second leading gen lep","p_{T} of leading gen AK4 jet", "#p_{T} of leading gen b","#Delta#phi between gen MET and leading gen lep","#Delta#phi between MET and second leading gen lep","#Delta#phi between gen MET and leading gen AK4 jet","#Delta#phi between gen MET and leading gen b","m^{leading gen lep}_{T}","m^{second leading gen lep}_{T}","R_{m}"};

  /*  for(int i=0;i<16;i++)
    {
      plot("EE_Summer20UL18_TTBar_DiLeptonic_signal_output.root",new_var_names[i],new_var_title[i]);
    }
  */
  const char *nbjetR_names[3] = {"bjetdelR1","bjetdelR2","bjetdelR3"};
  
  const char *nbjetR_title[3] = {"#DeltaR(bjet,AK8) when nbjet = 1","#DeltaR(bjet,AK8) when nbjet = 2","#DeltaR(bjet,AK8) when nbjet >=3"};

  for(int i=0;i<3;i++)
    {
      plot("test_output.root",nbjetR_names[i],nbjetR_title[i]);
    }
}
