#pragma once

#include "ofMain.h"
#include <cups/cups.h>


class ofxCUPS
{
    
public:
    ofxCUPS();
    ofxCUPS(string printerName);
    ~ofxCUPS();
    
    void listPrinters() const;
    vector<string> getPrinterList() const;
    string getDefaultPrinterName() const;
    void printImage(string filename) const;
    void printImage(string filename, bool isAbsolutePath) const;
    
    // Uses user defined default printer settings for printing the file
    void printImageWithDefaultOptions(string filename) const;
    void printImageWithDefaultOptions(string filename, bool isAbsolutePath) const;

    void updatePrinterInfo();
    void clearAllJobs() const;
    void checkActiveJobStatus() const;
    
    int getPrinterState() const;
    string getPrinterName() const;
    string getPrinterInfo() const;
    void setPrinterName(string newPrinterName);
    void setPrinterInfo(string newPrinterInfo);
    void setPrinterState(int newPrinterState);
    void setJobTitle(string newJobTitle);
    
    void addOption(string optionKey, string optionValue);
    void parseOptions(string optionString);
    
    
private:
    int printerState;
    int num_options; // Number of options currently in the options array.
    cups_option_t *options; // Pointer to options array
    string printerName;
    string printerInfo;
    string printOption;
    string jobTitle;
};
