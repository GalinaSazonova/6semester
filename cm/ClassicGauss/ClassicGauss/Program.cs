using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassicGauss
{
    class Program
    {
        static void Main(string[] args)
        {
            double[,] a = {{3.15, -1.18, 2.04, 0, 1.32, -5.18},
                   {0, 2.14, 1.71, 0, -2.01, -6.37},
                   {-1.11, 0, -3.16, 3.16, 1.14, 12.87},
                   {0, 0, 2.73, 4.2, 1.5, 1.74},
                   {0, 0, 0, 2.43, 4.51, 11.45}};
            int n = 6;
            Console.WriteLine("x1    x2    x3   x4   x5   b");
            for (int i = 0; i < n - 1; i++) 
            {
                 for (int j = 0; j < n; j++)
                 {
                     Console.Write(a[i, j].ToString() + " ");
                 }
                 //Console.Write(" " + a[i, n - 1].ToString());
  		         Console.WriteLine("");
  		    }
            Console.WriteLine("Контрольный столбец:");
            double[] control = new double[5]; 
            for (int i = 0; i < n - 1; i++)
            {
                control[i] = a[i, 5];
                for(int j = 0; j < n - 1; j++)
                {
                    control[i] += a[i, j];
                }
                Console.WriteLine(control[i] + " ");
            }

            double[] x = new double [a.Length/n];
            for (int z = 0; z < a.Length/n; z++)
             {
                 x[z] = a[z, n - 1];
             }
  		    double m;
  		    for (int k = 1; k < a.Length / n; k++) {
                 for (int j = k; j < a.Length / n; j++)
                 {
  				    m = a[j, k - 1] / a[k - 1, k - 1];
  				    for (int i = 0; i < n; i++) {
  					    a[j, i] = a[j, i] - m * a[k - 1, i];    
  				    }
                    control[j] = control[j] - m * control[k - 1];
                     x[j] = x[j] - m * x[k - 1];
  			    }
  		    }

             Console.WriteLine("Приведение к треугольному виду");
             Console.WriteLine("x1    x2    x3   x4   x5   b");
             for (int i = 0; i < n - 1; i++)
             {
                 for (int j = 0; j < n ; j++)
                 {
                     Console.Write(a[i, j].ToString() + " ");
                 }
                //Console.Write("= " + a[i, n - 1].ToString());
                 Console.WriteLine("");
             }
             Console.WriteLine("Суммы по строкам:");
             double[] control2 = new double[5];
             for (int i = 0; i < n - 1; i++)
             {
                 control2[i] = a[i, 5];
                 for (int j = 0; j < n - 1; j++)
                 {
                     control2[i] += a[i, j];
                 }
                 Console.WriteLine(control2[i] + " ");
             }

             Console.WriteLine("Контрольный столбец после преобразований:");
             for (int i = 0; i < n - 1; i++)
             {
                 Console.WriteLine(control[i]);
             }

             for (int i = a.Length / n - 1; i >= 0; i--)
             {
                 for (int j = i + 1; j < a.Length / n; j++) x[i] -= a[i, j] * x[j];
                 x[i] = x[i] / a[i, i];
             }
             Console.WriteLine("Ответ");
  		    for (int i = 0; i < x.Length; i++) {
  			    Console.WriteLine("x"+ i.ToString() + " = " + x[i]);
  		    }
            Console.WriteLine("Проверка:");
            Console.WriteLine("Ax ?  b");
            double[] check = new double[5];
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    check[i] += x[j] * a[i, j];  
                }
                Console.WriteLine(check[i] + " = " + a[i, 5]);
            }
           
             //Console.ReadKey();
        }
    }
}
