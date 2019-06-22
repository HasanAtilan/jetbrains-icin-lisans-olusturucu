#define CURL_STATICLIB
#include <stdio.h>
#include <curl/curl.h>
#include <string>

size_t veri_yaz(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t yaz;
    yaz = fwrite(ptr, size, nmemb, stream);
    return yaz;
}

int main(void)
{
    CURL *vericek;
    FILE *dosya;
    CURLcode basit;
    char *linkcek = "http://idea.lanyus.com/getkey";
    char dosyadi[FILENAME_MAX] = "C:\\getkey.txt";
    vericek = curl_easy_init();
    if (vericek)
    {
        dosya = fopen(dosyadi,"wb");
        curl_easy_setopt(vericek, CURLOPT_URL, linkcek);
        curl_easy_setopt(vericek, CURLOPT_WRITEFUNCTION, veri_yaz);
        curl_easy_setopt(vericek, CURLOPT_WRITEDATA, dosya);
        curl_easy_setopt (vericek, CURLOPT_VERBOSE, 1L);
        basit = curl_easy_perform(vericek);
        curl_easy_cleanup(vericek);
        fclose(dosya);
    }
    return 0;
}
