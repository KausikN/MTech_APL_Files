#include "ListADTArray.h"
#include "ElementType.h"
int main() {
    List a;
    int i;
    cout << "start pgm " << endl;
    a.makeNull();
    cout << " initialize List " << endl;
    for (i = 0; i < 10; i++)
        a.insert(i,a.end());
    cout << " Print List " << endl;
    a.printList();
    a.delItem(a.first());
    cout << "Print List after deleting an item " << endl;
    a.printList();
    a.delItem(a.next(a.first()));
        cout << "Print List after deleting an item next of first " << endl;
    a.printList();
    return 0;
}




/**************************************************************************
 * $Log$
 *
 * Local Variables:
 * time-stamp-active: t
 * time-stamp-line-limit: 20
 * time-stamp-start: "Last modified:[ 	]+"
 * time-stamp-format: "%3a %:d-%3b-%:y %02H:%02M:%02S by %u"
 * time-stamp-end: "$"
 * End:
 *                        End of ListMain.C
 **************************************************************************/
