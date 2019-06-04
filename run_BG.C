void runBG(int bin){

int count = 1;
for (int t = 0; t <= 2; t++){
	for (int w = 0; w<= 2; w++){
		for (int z = 0; z <= 2; z++){
			for( int h = 0; h <= 2; h++){

				if (count == bin) {
					cout << "Bin " << bin << Form("%d t, %d, W, %d Z, %d H", t, w, z, h) << endl;
					sampleEvents(t, z, w, h);
					gSystem->Exec(Form("mv sampled_shapes.root bgshape_bin%d.root", count));				
				}
				count++;


}}}}

}
