const dictionary& stressControl =
  mesh.solutionDict().subDict("solidMechanics");

int nCorr(readInt(stressControl.lookup("nCorrectors")));
scalar convergenceTolerance(readScalar(stressControl.lookup("DU")));
int infoFrequency(readInt(stressControl.lookup("infoFrequency")));
Switch aitkenRelax(stressControl.lookup("aitkenRelaxation"));
//Switch ensureTotalEquilibrium(stressControl.lookup("ensureTotalEquilibrium"));
