package dengue

import static org.springframework.http.HttpStatus.*
import grails.transaction.Transactional

@Transactional(readOnly = true)
class RegiaoController {

    static allowedMethods = [save: "POST", update: "PUT", delete: "DELETE"]

    def index(Integer max) {
        params.max = Math.min(max ?: 10, 100)
        respond Regiao.list(params), model:[regiaoInstanceCount: Regiao.count()]
    }

    def show(Regiao regiaoInstance) {
        respond regiaoInstance
    }

    def create() {
        respond new Regiao(params)
    }

    @Transactional
    def save(Regiao regiaoInstance) {

        if (regiaoInstance == null) {
            notFound()
            return
        }

        if (regiaoInstance.hasErrors()) {
            respond regiaoInstance.errors, view:'create'
            return
        }
        sad(regiaoInstance)
        regiaoInstance.save flush:true

        request.withFormat {
            form multipartForm {
                flash.message = message(code: 'default.created.message', args: [message(code: 'regiao.label', default: 'Regiao'), regiaoInstance.id])
                redirect regiaoInstance
            }
            '*' { respond regiaoInstance, [status: CREATED] }
        }
    }

    def edit(Regiao regiaoInstance) {
        respond regiaoInstance
    }

    @Transactional
    def update(Regiao regiaoInstance) {
        if (regiaoInstance == null) {
            notFound()
            return
        }

        if (regiaoInstance.hasErrors()) {
            respond regiaoInstance.errors, view:'edit'
            return
        }

        regiaoInstance.save flush:true

        request.withFormat {
            form multipartForm {
                flash.message = message(code: 'default.updated.message', args: [message(code: 'Regiao.label', default: 'Regiao'), regiaoInstance.id])
                redirect regiaoInstance
            }
            '*'{ respond regiaoInstance, [status: OK] }
        }
    }

    @Transactional
    def delete(Regiao regiaoInstance) {

        if (regiaoInstance == null) {
            notFound()
            return
        }

        regiaoInstance.delete flush:true

        request.withFormat {
            form multipartForm {
                flash.message = message(code: 'default.deleted.message', args: [message(code: 'Regiao.label', default: 'Regiao'), regiaoInstance.id])
                redirect action:"index", method:"GET"
            }
            '*'{ render status: NO_CONTENT }
        }
    }

    protected void notFound() {
        request.withFormat {
            form multipartForm {
                flash.message = message(code: 'default.not.found.message', args: [message(code: 'regiao.label', default: 'Regiao'), params.id])
                redirect action: "index", method: "GET"
            }
            '*'{ render status: NOT_FOUND }
        }
    }

    private static int retornaRegiao(String regiao){
        if (regiao.equals("Nordeste")) {
            return 1
        }
        else if (regiao.equals("Norte")) {
            return 2
        }
        else if (regiao.equals("Sudeste")) {
            return 3
        }
        else if (regiao.equals("Sul")) {
            return 4
        }
        else return 5
    }

    private static void escreveArquivo(int idRegiao){
        def arquivo ="entrada.txt"
        File limpaArquivo = new File(arquivo)
        File gravaArquivo = new File(arquivo)

        limpaArquivo.write("")
        gravaArquivo.append(idRegiao)
        gravaArquivo.append("")
    }

    private static void executaInteligencia(){
        "./sad".execute()
    }

    private static String leArquivo(){
        File arquivo= new File("arquivoSaida.txt")
        String paracetomol = arquivo.getText()
        return paracetomol
   }

    private static  void sad(Regiao regiaoInstance){
        int idRegiao
        idRegiao = retornaRegiao(regiaoInstance.regiao)
        escreveArquivo(idRegiao)
        executaInteligencia()
        regiaoInstance.paracetomol = leArquivo()
    }


}
