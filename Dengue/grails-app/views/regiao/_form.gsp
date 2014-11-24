<%@ page import="dengue.Regiao" %>



<div class="fieldcontain ${hasErrors(bean: regiaoInstance, field: 'regiao', 'error')} required">
	<label for="regiao">
		<g:message code="regiao.regiao.label" default="Regiao" />
		<span class="required-indicator">*</span>
	</label>
	<g:select name="regiao" from="${regiaoInstance.constraints.regiao.inList}" required="" value="${regiaoInstance?.regiao}" valueMessagePrefix="regiao.regiao"/>
</div>

